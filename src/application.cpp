#include "application.h"
#include <SDL2/SDL_image.h>
#include "inplaystate.h"
#include "verbs.h"
Application::~Application()
{
   	IMG_Quit();
	SDL_Quit();
}
constexpr int TEXTURE_REGION_COLUMNS = 16;
constexpr int TEXTURE_REGION_ROWS = 16;
Application::Application(
    const std::string& title, 
    int screenWidth, 
    int screenHeight, 
    int viewWidth, 
    int viewHeight,
    size_t viewColumns,
    size_t viewRows,
    int viewCellWidth,
    int viewCellHeight,
    const std::string& textureFilename)
    : _window(nullptr, SDL_DestroyWindow)
    , _renderer(nullptr, SDL_DestroyRenderer)
    , _texture(nullptr, SDL_DestroyTexture)
    , _frameBuffer(viewColumns, viewRows)
    , _tileSet()
    , _plotter(0,0,viewCellWidth,viewCellHeight)
    , _palette()
    , _frameBufferRenderer(_frameBuffer, _tileSet, _plotter, _palette)
    , _commandBuffer()
	, _column(viewColumns/2)
	, _row(viewRows/2)
	, _states()
	, _state(std::nullopt)
	, _worldData()
	, _world(_worldData)
{
	Verbs::Initialize();
	_world.Initialize();
	_palette.SetColor(FrameBufferCellColor::BLACK,{0,0,0,255});
	_palette.SetColor(FrameBufferCellColor::BLUE,{0,0,170,255});
	_palette.SetColor(FrameBufferCellColor::GREEN,{0,170,0,255});
	_palette.SetColor(FrameBufferCellColor::CYAN,{0,170,170,255});
	_palette.SetColor(FrameBufferCellColor::RED,{170,0,0,255});
	_palette.SetColor(FrameBufferCellColor::MAGENTA,{170,0,170,255});
	_palette.SetColor(FrameBufferCellColor::BROWN,{170,85,0,255});
	_palette.SetColor(FrameBufferCellColor::LIGHT_GRAY,{170,170,170,255});
	_palette.SetColor(FrameBufferCellColor::DARK_GRAY,{85,85,85,255});
	_palette.SetColor(FrameBufferCellColor::LIGHT_BLUE,{85,85,255,255});
	_palette.SetColor(FrameBufferCellColor::LIGHT_GREEN,{85,255,85,255});
	_palette.SetColor(FrameBufferCellColor::LIGHT_CYAN,{85,255,255,255});
	_palette.SetColor(FrameBufferCellColor::LIGHT_RED,{255,85,85,255});
	_palette.SetColor(FrameBufferCellColor::LIGHT_MAGENTA,{255,85,255,255});
	_palette.SetColor(FrameBufferCellColor::YELLOW,{255,255,85,255});
	_palette.SetColor(FrameBufferCellColor::WHITE,{255,255,255,255});
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    _window.reset(SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            screenWidth, 
            screenHeight,
            SDL_WINDOW_SHOWN));
    _renderer.reset(SDL_CreateRenderer(_window.get(), -1, 0));
    _texture.reset(IMG_LoadTexture(_renderer.get(), textureFilename.c_str()));
    _tileSet.Add(_texture.get(),viewCellWidth,viewCellHeight);
    SDL_RenderSetLogicalSize(_renderer.get(), viewWidth, viewHeight);
	_states.emplace(GameStateType::IN_PLAY, std::make_unique<InPlayState>(_world, _frameBuffer));
	_state = GameStateType::IN_PLAY;
}
void Application::Update()
{
	if(!_state)
	{
		return;
	}
	do
	{
		auto command = _commandBuffer.Read();
		if(!command) break;
		_states[*_state]->HandleCommand(*command);
	} while (true);
}
void Application::Draw()
{
	if(!_state)
	{
		return;
	}
	_states[*_state]->Draw();
    SDL_RenderClear(_renderer.get());
    _frameBufferRenderer.Render(_renderer.get());
    SDL_RenderPresent(_renderer.get());
}
static std::map<SDL_Keycode, CommandType> keycodeCommands = 
{
	{ SDLK_w         , CommandType::UP     },
	{ SDLK_z         , CommandType::UP     },
	{ SDLK_UP        , CommandType::UP     },
	{ SDLK_a         , CommandType::LEFT   },
	{ SDLK_q         , CommandType::LEFT   },
	{ SDLK_LEFT      , CommandType::LEFT   },
	{ SDLK_s         , CommandType::DOWN   },
	{ SDLK_DOWN      , CommandType::DOWN   },
	{ SDLK_d         , CommandType::RIGHT  },
	{ SDLK_RIGHT     , CommandType::RIGHT  },
	{ SDLK_SPACE     , CommandType::GREEN  },
	{ SDLK_BACKSPACE , CommandType::RED    },
	{ SDLK_ESCAPE    , CommandType::RED    },
	{ SDLK_TAB       , CommandType::YELLOW },
	{ SDLK_RETURN    , CommandType::BLUE   }
};
void Application::Loop()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) 
	{
		if(event.type == SDL_QUIT)
		{
			_state = std::nullopt;
            return;
		}
		else if(event.type == SDL_KEYDOWN)
		{
			auto iter = keycodeCommands.find(event.key.keysym.sym);
			if(iter!=keycodeCommands.end())
			{
				_commandBuffer.Write(iter->second);
			}
		}
    }
	Update();
	Draw();
}
void Application::Run()
{
    while(_state)
    {
        Loop();
    }
}
