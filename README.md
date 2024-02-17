# Logging Project

This C++ logging project provides a simple yet effective way to manage log messages of different levels: "warn", "error", and "info". It also includes custom implementations of a date class and a string class.

## Features

- **Log Levels**: The logging system supports three levels of logs:
  - **Warning (Warn)**: Messages indicating potential issues that do not necessarily cause immediate failure.
  - **Error**: Messages indicating critical errors that require immediate attention.
  - **Information (Info)**: General information messages for tracking application behavior.

- **Custom Date Class with Cache Functionality**: The project includes a custom implementation of a date class with cache functionality. The date is embedded with log messages, and the cache ensures that the date is computed only once per day if logging multiple messages on the same day.

- **Custom String Class**: It also includes a custom implementation of a string class for managing character strings efficiently.

## Usage

1. **Setting Log Level**: To set the log level, use the `SetLogLevel()` method of the `Log` class instance. Example:
    ```cpp
    Log log;
    log.SetLogLevel(Log::Level::LevelWarning); // Set log level to Warning
    ```

2. **Logging Messages with Embedded Date**: Use the `Info()`, `Warn()`, and `Error()` methods of the `Log` class to log messages of different levels. The date will be automatically embedded with each log message. Example:
    ```cpp
    log.Info("This is an information message.",1,"Info");
    log.Warn("This is a warning message.",2.1, 'W');
    log.Error("This is an error message.",1+2.1,String{"Error"});
    ```

## Contributing

Contributions are welcome! Feel free to submit bug reports, feature requests, or pull requests via GitHub.

