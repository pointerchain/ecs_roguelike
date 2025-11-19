// src/loader.cpp

#include <fstream>
#include <vector>

namespace {

std::vector<char> ReadFile(const std::string& filename) {
  std::ifstream file(filename, std::ios::binary | std::ios::ate);
  if (!file) return {};

  std::streamsize size = file.tellg();
  file.seekg(0, std::ios::beg);

  std::vector<char> buffer(size);
  if (file.read(buffer.data(), size)) {
    return buffer;
  }
  return {};
}

}  // namespace
