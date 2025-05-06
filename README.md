# C++ CMake/VSCode/Conan Template Project

This is a template project for a C++ application using modern CMake for the configuration, Conan 2 for resolving external libraries, and VSCode for the code editing/debug.

## How to use
You simply add your .cpp files in the `src` directory, and your .h files in the `include` directory. Subdirectories are automatically searched for.

To add an external libray as dependency simply edit the `conanfile.txt` file, and add a corresponding `find_package` command in the `CMakeLists.txt` file, and add the library to the `target_link_libraries` command at the end of the `CMakeLists.txt`.

## How to compile your project

- You need at least a compiler (e.g., g++), cmake, conan2 (for resolving dependencies), and a build system, such as Ninja or make. On Windows, Visual Studio (not Code) acts as both a compiler and build system.

- Clone the repository recursively with:

     `git clone --recursive https://github.com/marco-calautti/conan-cmake-vscode-template.git`

- There are different CMake presets, depending on the OS and tooling used:
    - Linux/macOS with Ninja: `debug-ninja` and `release-ninja` 
    - Linux/macOS with make: `debug-makefiles` and `release-makefiles`
    - Windows: `msvc`. Whether it is a release or debug build will be specified at build time.

- Configure the desired preset with `cmake --preset <preset-name>`.

- The above command will resolve all dependencies by finding them using Conan 2.

- Now build the project with:
    - Linux/macOS: `cmake --build build`
    - Windows `cmake --build build --config Release`. Change `Release` to `Debug` if you need a debug build.

## Code and Debug with VSCode/VSCodium

- To code with intellisense and to debug the project with VSCode, you can install the `Microsoft's C/C++` extension, together with the `CMake Tools` extension.

- If you want to use VSCodium, you instead need the extensions `ccls`, `CMake Tools`, and `CodeLLDB`, and have the `ccls` language server installed on your system. Then, for enabling intellisense and debugging using VSCodium with the above extensions, you need to configure the `CMake Tools` extensions and the `ccls` extension: this is done in the provided `settings.json` in the `.vscode` directory. If using VSCode, you don't need any special configuration and you can remove the .vscode directory.

- To debug run the following VSCode/Codium commands:
    - `CMake Select Configure Preset` and choose the debug preset. On Windows, simply choose the `msvc` preset and then select the `Debug` variant with the command `CMake: Select Variant`.
    - `CMake Configure`
    - `CMake Build`
    - `CMake Debug`

- When adding new dependencies with conan, or adding other subprojects to the CMake Project, after you configure the CMake project, restart the ccls server with the `ccls: Restart Language Server` command in VSCodium, to reindex all include directories.