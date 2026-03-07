#include "application.h"
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
constexpr std::string_view METAPHOR_TITLE = "The Beryl Chamber";
constexpr std::string_view TEXTURE_FILENAME = "romfont8x8.png";
constexpr size_t VIEW_COLUMNS = 40;
constexpr size_t VIEW_ROWS = 25;
constexpr size_t VIEW_CELL_WIDTH = 8;
constexpr size_t VIEW_CELL_HEIGHT = 8;
constexpr size_t VIEW_WIDTH = VIEW_COLUMNS * VIEW_CELL_WIDTH;
constexpr size_t VIEW_HEIGHT = VIEW_ROWS * VIEW_CELL_HEIGHT;
constexpr size_t SCALE = 4;
constexpr size_t SCREEN_WIDTH = VIEW_WIDTH * SCALE;
constexpr size_t SCREEN_HEIGHT = VIEW_HEIGHT * SCALE;
int main(int, char**) {
    Application application(
        METAPHOR_TITLE.data(),
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        VIEW_WIDTH,
        VIEW_HEIGHT,
        TEXTURE_FILENAME.data());
#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg([](void* arg){static_cast<Application*>(arg)->Loop();}, &application, 0, 1);
#else
    application.Run();
#endif
    return 0;
}
