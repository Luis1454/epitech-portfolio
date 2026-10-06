# 🚀 Guide du Server

Required dependencies:
- Asio
- C++
- CMake

To launch the client, follow these steps:

1. Open a terminal or command prompt in the project folder.
2. Navigate to the server directory (or wherever your client source code is located).
3. Run the following commands:

    ```bash
    cmake .
    cmake --build .
    ```

4. Finally, launch the server:

    ```bash
    ./r-type server
    ```

A compilation flag exists to choose the port:

```bash
./r-type server -p 8080
```