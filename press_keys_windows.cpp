#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <any>
#include <array>
#include <atomic>
#include <barrier>
#include <bit>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <charconv>
#include <chrono>
#include <cinttypes>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <concepts>
#include <condition_variable>
#include <coroutine>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <execution>
#include <filesystem>
#include <format>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <latch>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <memory_resource>
#include <mutex>
#include <new>
#include <numbers>
#include <numeric>
#include <optional>
#include <ostream>
#include <queue>
#include <random>
#include <ranges>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <set>
#include <shared_mutex>
#include <source_location>
#include <span>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <stop_token>
#include <streambuf>
#include <string>
#include <string_view>
#include <syncstream>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <variant>
#include <vector>
#ifdef _WIN32
#include <windows.h>
#define EXEC_CMD(command, mode) _popen(command, mode)
#define CLOSE_CMD(pipe) _pclose(pipe)
#else
#include <unistd.h>
#define EXEC_CMD(command, mode) popen(command, mode)
#define CLOSE_CMD(pipe) pclose(pipe)
#endif
static void sleepcp(int milliseconds);

void static sleepcp(int milliseconds)
{
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}
void static sleepcp(int milliseconds);
#include <windows.h>

void static checkSendInput(UINT result)
{
    if (result == 0)
    {
        throw std::runtime_error("SendInput failed with error: " + std::to_string(GetLastError()));
    }
}

void Press(int hexKeyCode, int sleep_ms = 500)
{
    struct tagINPUT input{};
    input.type = INPUT_KEYBOARD;
    input.ki = KEYBDINPUT(static_cast<WORD>(hexKeyCode));

    checkSendInput(SendInput(1, &input, sizeof(INPUT)));
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_ms));

    input.ki.dwFlags = KEYEVENTF_KEYUP;
    checkSendInput(SendInput(1, &input, sizeof(INPUT)));
}

static const std::unordered_map<std::string, int> VK_CODE = {
    {"control-break processing", 3},
    {"backspace", 8},
    {"tab", 9},
    {"clear", 254},
    {"enter", 13},
    {"shift", 16},
    {"ctrl", 17},
    {"alt", 18},
    {"pause", 19},
    {"caps lock", 20},
    {"ime hangul mode", 21},
    {"ime junja mode", 23},
    {"ime final mode", 24},
    {"ime kanji mode", 25},
    {"esc", 27},
    {"ime convert", 28},
    {"ime nonconvert", 29},
    {"ime accept", 30},
    {"ime mode change request", 31},
    {"spacebar", 32},
    {"page up", 33},
    {"page down", 34},
    {"end", 35},
    {"home", 36},
    {"left", 37},
    {"up", 38},
    {"right", 39},
    {"down", 40},
    {"select", 41},
    {"print", 42},
    {"execute", 43},
    {"print screen", 44},
    {"insert", 45},
    {"delete", 46},
    {"help", 47},
    {"0", 96},
    {"1", 97},
    {"2", 98},
    {"3", 99},
    {"4", 100},
    {"5", 101},
    {"6", 102},
    {"7", 103},
    {"8", 104},
    {"9", 105},
    {"a", 65},
    {"b", 66},
    {"c", 67},
    {"d", 68},
    {"e", 69},
    {"f", 70},
    {"g", 71},
    {"h", 72},
    {"i", 73},
    {"j", 74},
    {"k", 75},
    {"l", 76},
    {"m", 77},
    {"n", 78},
    {"o", 79},
    {"p", 80},
    {"q", 81},
    {"r", 82},
    {"s", 83},
    {"t", 84},
    {"u", 85},
    {"v", 86},
    {"w", 87},
    {"x", 88},
    {"y", 89},
    {"z", 90},
    {"left windows", 91},
    {"right windows", 92},
    {"applications", 93},
    {"sleep", 95},
    {"*", 106},
    {"+", 187},
    {"separator", 108},
    {"-", 189},
    {"decimal", 110},
    {"/", 111},
    {"f1", 112},
    {"f2", 113},
    {"f3", 114},
    {"f4", 115},
    {"f5", 116},
    {"f6", 117},
    {"f7", 118},
    {"f8", 119},
    {"f9", 120},
    {"f10", 121},
    {"f11", 122},
    {"f12", 123},
    {"f13", 124},
    {"f14", 125},
    {"f15", 126},
    {"f16", 127},
    {"f17", 128},
    {"f18", 129},
    {"f19", 130},
    {"f20", 131},
    {"f21", 132},
    {"f22", 133},
    {"f23", 134},
    {"f24", 135},
    {"num lock", 144},
    {"scroll lock", 145},
    {"left shift", 160},
    {"right shift", 161},
    {"left ctrl", 162},
    {"right ctrl", 163},
    {"left menu", 164},
    {"right menu", 165},
    {"browser back", 166},
    {"browser forward", 167},
    {"browser refresh", 168},
    {"browser stop", 169},
    {"browser search key", 170},
    {"browser favorites", 171},
    {"browser start and home", 172},
    {"volume mute", 173},
    {"volume down", 174},
    {"volume up", 175},
    {"next track", 176},
    {"previous track", 177},
    {"stop media", 178},
    {"play/pause media", 179},
    {"start mail", 180},
    {"select media", 181},
    {"start application 1", 182},
    {"start application 2", 183},
    {",", 188},
    {".", 190},
    {"ime process", 229},
    {"attn", 246},
    {"crsel", 247},
    {"exsel", 248},
    {"erase eof", 249},
    {"play", 250},
    {"zoom", 251},
    {"reserved ", 252},
    {"pa1", 253},
    {"CONTROL-BREAK PROCESSING", 3},
    {"BACKSPACE", 8},
    {"TAB", 9},
    {"CLEAR", 254},
    {"ENTER", 13},
    {"SHIFT", 16},
    {"CTRL", 17},
    {"ALT", 18},
    {"PAUSE", 19},
    {"CAPS LOCK", 20},
    {"IME HANGUL MODE", 21},
    {"IME JUNJA MODE", 23},
    {"IME FINAL MODE", 24},
    {"IME KANJI MODE", 25},
    {"ESC", 27},
    {"IME CONVERT", 28},
    {"IME NONCONVERT", 29},
    {"IME ACCEPT", 30},
    {"IME MODE CHANGE REQUEST", 31},
    {"SPACEBAR", 32},
    {"PAGE UP", 33},
    {"PAGE DOWN", 34},
    {"END", 35},
    {"HOME", 36},
    {"LEFT", 37},
    {"UP", 38},
    {"RIGHT", 39},
    {"DOWN", 40},
    {"SELECT", 41},
    {"PRINT", 42},
    {"EXECUTE", 43},
    {"PRINT SCREEN", 44},
    {"INSERT", 45},
    {"DELETE", 46},
    {"HELP", 47},
    {"A", 65},
    {"B", 66},
    {"C", 67},
    {"D", 68},
    {"E", 69},
    {"F", 70},
    {"G", 71},
    {"H", 72},
    {"I", 73},
    {"J", 74},
    {"K", 75},
    {"L", 76},
    {"M", 77},
    {"N", 78},
    {"O", 79},
    {"P", 80},
    {"Q", 81},
    {"R", 82},
    {"S", 83},
    {"T", 84},
    {"U", 85},
    {"V", 86},
    {"W", 87},
    {"X", 88},
    {"Y", 89},
    {"Z", 90},
    {"LEFT WINDOWS", 91},
    {"RIGHT WINDOWS", 92},
    {"APPLICATIONS", 93},
    {"SLEEP", 95},
    {"SEPARATOR", 108},
    {"DECIMAL", 110},
    {"F1", 112},
    {"F2", 113},
    {"F3", 114},
    {"F4", 115},
    {"F5", 116},
    {"F6", 117},
    {"F7", 118},
    {"F8", 119},
    {"F9", 120},
    {"F10", 121},
    {"F11", 122},
    {"F12", 123},
    {"F13", 124},
    {"F14", 125},
    {"F15", 126},
    {"F16", 127},
    {"F17", 128},
    {"F18", 129},
    {"F19", 130},
    {"F20", 131},
    {"F21", 132},
    {"F22", 133},
    {"F23", 134},
    {"F24", 135},
    {"NUM LOCK", 144},
    {"SCROLL LOCK", 145},
    {"LEFT SHIFT", 160},
    {"RIGHT SHIFT", 161},
    {"LEFT CTRL", 162},
    {"RIGHT CTRL", 163},
    {"LEFT MENU", 164},
    {"RIGHT MENU", 165},
    {"BROWSER BACK", 166},
    {"BROWSER FORWARD", 167},
    {"BROWSER REFRESH", 168},
    {"BROWSER STOP", 169},
    {"BROWSER SEARCH KEY", 170},
    {"BROWSER FAVORITES", 171},
    {"BROWSER START AND HOME", 172},
    {"VOLUME MUTE", 173},
    {"VOLUME DOWN", 174},
    {"VOLUME UP", 175},
    {"NEXT TRACK", 176},
    {"PREVIOUS TRACK", 177},
    {"STOP MEDIA", 178},
    {"PLAY/PAUSE MEDIA", 179},
    {"START MAIL", 180},
    {"SELECT MEDIA", 181},
    {"START APPLICATION 1", 182},
    {"START APPLICATION 2", 183},
    {"IME PROCESS", 229},
    {"ATTN", 246},
    {"CRSEL", 247},
    {"EXSEL", 248},
    {"ERASE EOF", 249},
    {"PLAY", 250},
    {"ZOOM", 251},
    {"RESERVED ", 252},
    {"PA1", 253},
    {"CONTROL-BREAK_PROCESSING", 3},
    {"CAPS_LOCK", 20},
    {"IME_HANGUL_MODE", 21},
    {"IME_JUNJA_MODE", 23},
    {"IME_FINAL_MODE", 24},
    {"IME_KANJI_MODE", 25},
    {"IME_CONVERT", 28},
    {"IME_NONCONVERT", 29},
    {"IME_ACCEPT", 30},
    {"IME_MODE_CHANGE_REQUEST", 31},
    {"PAGE_UP", 33},
    {"PAGE_DOWN", 34},
    {"PRINT_SCREEN", 44},
    {"LEFT_WINDOWS", 91},
    {"RIGHT_WINDOWS", 92},
    {"NUM_LOCK", 144},
    {"SCROLL_LOCK", 145},
    {"LEFT_SHIFT", 160},
    {"RIGHT_SHIFT", 161},
    {"LEFT_CTRL", 162},
    {"RIGHT_CTRL", 163},
    {"LEFT_MENU", 164},
    {"RIGHT_MENU", 165},
    {"BROWSER_BACK", 166},
    {"BROWSER_FORWARD", 167},
    {"BROWSER_REFRESH", 168},
    {"BROWSER_STOP", 169},
    {"BROWSER_SEARCH_KEY", 170},
    {"BROWSER_FAVORITES", 171},
    {"BROWSER_START_AND_HOME", 172},
    {"VOLUME_MUTE", 173},
    {"VOLUME_DOWN", 174},
    {"VOLUME_UP", 175},
    {"NEXT_TRACK", 176},
    {"PREVIOUS_TRACK", 177},
    {"STOP_MEDIA", 178},
    {"PLAY/PAUSE_MEDIA", 179},
    {"START_MAIL", 180},
    {"SELECT_MEDIA", 181},
    {"START_APPLICATION_1", 182},
    {"START_APPLICATION_2", 183},
    {"IME_PROCESS", 229},
    {"ERASE_EOF", 249},
    {"RESERVED_", 252},
    {"control-break_processing", 3},
    {"caps_lock", 20},
    {"ime_hangul_mode", 21},
    {"ime_junja_mode", 23},
    {"ime_final_mode", 24},
    {"ime_kanji_mode", 25},
    {"ime_convert", 28},
    {"ime_nonconvert", 29},
    {"ime_accept", 30},
    {"ime_mode_change_request", 31},
    {"page_up", 33},
    {"page_down", 34},
    {"print_screen", 44},
    {"left_windows", 91},
    {"right_windows", 92},
    {"num_lock", 144},
    {"scroll_lock", 145},
    {"left_shift", 160},
    {"right_shift", 161},
    {"left_ctrl", 162},
    {"right_ctrl", 163},
    {"left_menu", 164},
    {"right_menu", 165},
    {"browser_back", 166},
    {"browser_forward", 167},
    {"browser_refresh", 168},
    {"browser_stop", 169},
    {"browser_search_key", 170},
    {"browser_favorites", 171},
    {"browser_start_and_home", 172},
    {"volume_mute", 173},
    {"volume_down", 174},
    {"volume_up", 175},
    {"next_track", 176},
    {"previous_track", 177},
    {"stop_media", 178},
    {"play/pause_media", 179},
    {"start_mail", 180},
    {"select_media", 181},
    {"start_application_1", 182},
    {"start_application_2", 183},
    {"ime_process", 229},
    {"erase_eof", 249},
    {"reserved_", 252},

};

int main()
{
    sleepcp(10000);
    Press(VK_CODE.at("A"));
    Press(VK_CODE.at("B"));
    Press(VK_CODE.at("C"));
    Press(VK_CODE.at("D"));
    Press(VK_CODE.at("E"));

    return 0;
}
