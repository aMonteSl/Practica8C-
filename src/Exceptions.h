#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

/**
 * @file Exceptions.h
 * @brief This file contains the attributes and methods of the Exceptions class.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

class FileOpenError : public std::runtime_error {
public:
  /**
   * @brief Construct a new File Open Error object
   *
   * @param filename
   */
  explicit FileOpenError(const std::string &filename)
      : std::runtime_error("Error opening file: " + filename) {}
};

class FileCloseError : public std::runtime_error {
public:
  /**
   * @brief Construct a new File Close Error object
   *
   * @param filename
   */
  explicit FileCloseError(const std::string &filename)
      : std::runtime_error("Error closing file: " + filename) {}
};

class FileReadError : public std::runtime_error {
public:
  /**
   * @brief Construct a new File Read Error object
   *
   * @param filename
   */
  explicit FileReadError(const std::string &filename)
      : std::runtime_error("Error reading file: " + filename) {}
};

class FileWriteError : public std::runtime_error {
public:
  /**
   * @brief Construct a new File Write Error object
   *
   * @param filename
   */
  explicit FileWriteError(const std::string &filename)
      : std::runtime_error("Error writing file: " + filename) {}
};

class FilePermissionError : public std::runtime_error {
public:
  /**
   * @brief Construct a new File Permission Error object
   *
   * @param filename
   */
  explicit FilePermissionError(const std::string &filename)
      : std::runtime_error("Permission denied: " + filename) {}
};

class FileNotFoundError : public std::runtime_error {
public:
  /**
   * @brief Construct a new File Not Found Error object
   *
   * @param filename
   */
  explicit FileNotFoundError(const std::string &filename)
      : std::runtime_error("File not found: " + filename) {}
};

class FileLockError : public std::runtime_error {
public:
  /**
   * @brief Construct a new File Lock Error object
   *
   * @param filename
   */
  explicit FileLockError(const std::string &filename)
      : std::runtime_error("File is locked: " + filename) {}
};

class FileCorruptError : public std::runtime_error {
public:
  /**
   * @brief Construct a new File Corrupt Error object
   *
   * @param filename
   */
  explicit FileCorruptError(const std::string &filename)
      : std::runtime_error("File is corrupt: " + filename) {}
};

#endif // EXCEPTIONS_H