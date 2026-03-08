#include "application.h"
#include <SDL2/SDL_image.h>
static bool quit = false;//TODO: make this based on a optional gamestate variable instead
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
{
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
    _frameBuffer.Fill(size_t{0},size_t{0},_frameBuffer.GetColumns(),1,219,FrameBufferCellColor::BLUE,FrameBufferCellColor::BLACK);
    _frameBuffer.Fill(size_t{0},_frameBuffer.GetRows() - 1,_frameBuffer.GetColumns(),1,219,FrameBufferCellColor::BLUE,FrameBufferCellColor::BLACK);
    _frameBuffer.Fill(size_t{0},size_t{1},1,_frameBuffer.GetRows() - 2,219,FrameBufferCellColor::BLUE,FrameBufferCellColor::BLACK);
    _frameBuffer.Fill(_frameBuffer.GetColumns() - 1,size_t{1},1,_frameBuffer.GetRows() - 2,219,FrameBufferCellColor::BLUE,FrameBufferCellColor::BLACK);
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
			quit = true;
            break;
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
	do
	{
		auto command = _commandBuffer.Read();
		if(!command) break;
		size_t nextColumn = _column;
		size_t nextRow = _row;
		switch(*command)
		{
			case CommandType::UP:
				nextRow--;
				break;
			case CommandType::DOWN:
				nextRow++;
				break;
			case CommandType::LEFT:
				nextColumn--;
				break;
			case CommandType::RIGHT:
				nextColumn++;
				break;
			default:
				break;
		}
		if(_frameBuffer.GetCell(nextColumn, nextRow).GetCharacter()==219)
		{
			nextColumn = _column;
			nextRow = _row;
		}
		_column = nextColumn;
		_row = nextRow;
	} while (true);
    SDL_RenderClear(_renderer.get());
	_frameBuffer.SetCell(_column, _row, '@', FrameBufferCellColor::LIGHT_GRAY, std::nullopt);
    _frameBufferRenderer.Render(_renderer.get());
	_frameBuffer.SetCell(_column, _row, 0, FrameBufferCellColor::BLACK, std::nullopt);
    SDL_RenderPresent(_renderer.get());
}
void Application::Run()
{
    while(!quit)
    {
        Loop();
    }
}
