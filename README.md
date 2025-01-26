# Build Your Own HTTP Server in C++

[![progress-banner](https://backend.codecrafters.io/progress/http-server/a8ecd715-c17a-43a7-9260-3d956c76eadd)](https://github.com/your-username/http-server)

This project is a C++ implementation of an HTTP/1.1 server. The goal is to build a fully functional HTTP server capable of handling multiple client requests, while learning about networking concepts, TCP servers, and the HTTP protocol in the process.

---

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Setup Instructions](#setup-instructions)
- [How to Run](#how-to-run)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)

---

## Introduction

HTTP (HyperText Transfer Protocol) is the backbone of the World Wide Web. This project aims to create a lightweight HTTP/1.1 server from scratch. You will understand the underlying mechanisms of HTTP, socket programming, and multithreaded servers as you progress through the stages of this implementation.

---

## Features

- **Basic HTTP/1.1 Support**: Handle `GET` requests and serve static files.
- **Multithreading**: Serve multiple client requests simultaneously.
- **Customizable Routes**: Add handlers for different endpoints easily.
- **Standards Compliant**: Follows HTTP/1.1 protocol specifications.
- **Educational**: Learn socket programming and HTTP request/response handling.

---

## Project Structure

```plaintext
.
├── src/
│   ├── server.cpp      # Entry point for the HTTP server
├── include/
│   ├── http_parser.h   # Header file for the HTTP parser
│   ├── router.h        # Header file for route handling
│   └── utils.h         # Header file for utility functions
├── tests/              # Unit tests for individual components
├── CMakeLists.txt      # Build system configuration
└── README.md           # This file
```

---

## Getting Started

### Prerequisites

Make sure you have the following tools installed on your system:

- **C++ Compiler**: GCC/Clang with C++17 or higher support.
- **CMake**: Version 3.10 or higher.
- **Git**: For version control.

### Setup Instructions

1. Clone the repository:

   ```sh
   git clone https://github.com/your-username/http-server.git
   cd http-server
   ```

2. Create a build directory:

   ```sh
   mkdir build && cd build
   ```

3. Run CMake to configure the project:

   ```sh
   cmake ..
   ```

4. Build the project:

   ```sh
   make
   ```

---

## How to Run

Once the build is complete, you can run the server using:

```sh
./your_program.sh
```

By default, the server listens on port `8080`. You can test it by opening a web browser and navigating to `http://localhost:8080`.

---

## Testing

This project includes unit tests for core components. To run the tests:

1. Navigate to the build directory:

   ```sh
   cd build
   ```

2. Run the tests:

   ```sh
   ./run_tests
   ```

Testing ensures that your server behaves as expected and adheres to the HTTP/1.1 specification.

---

## Contributing

Contributions are welcome! If you’d like to add features or improve the existing implementation:

1. Fork the repository.
2. Create a new branch for your feature/bugfix.
3. Commit your changes with clear messages.
4. Submit a pull request for review.

---

## License

This project is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute the code as per the license terms.

---

## Acknowledgments

This project is inspired by the "Build Your Own HTTP Server" challenge on Codecrafters.io. It serves as a learning opportunity for understanding HTTP, socket programming, and multithreading concepts in C++.


