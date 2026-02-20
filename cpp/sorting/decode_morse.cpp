#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

std::string decode_morse(const std::string& encoded){

  static const std::unordered_map<std::string, std::string> MORSE_CODE = {
    {".-", "A"}, {"-...", "B"}, {"-.-.", "C"}, {"-..", "D"}, {".", "E"},
    {"..-.", "F"}, {"--.", "G"}, {"....", "H"}, {"..", "I"}, {".---", "J"},
    {"-.-", "K"}, {".-..", "L"}, {"--", "M"}, {"-.", "N"}, {"---", "O"},
    {".--.", "P"}, {"--.-", "Q"}, {".-.", "R"}, {"...", "S"}, {"-", "T"},
    {"..-", "U"}, {"...-", "V"}, {".--", "W"}, {"-..-", "X"}, {"-.--", "Y"},
    {"--..", "Z"}, {".----", "1"}, {"..---", "2"}, {"...--", "3"}, {"....-", "4"},
    {".....", "5"}, {"-....", "6"}, {"--...", "7"}, {"---..", "8"}, {"----.", "9"},
    {"-----", "0"}
  };

  std::istringstream iss(encoded);
  std::ostringstream oss;
  std::string token;

  auto decoke_token = [](std::string& token) -> std::string {
    if (token == ""){
      return " ";
    }

    auto it = MORSE_CODE.find(token);
    return(it != MORSE_CODE.end()) ? std::string(it->second) : " "; 
  };

  while(iss >> token ){
    oss << decoke_token(token);
  }


  std::string result = oss.str();
  std::istringstream result_iss(result);
  std::vector<std::string> words;

  while (result_iss >> token){
    words.push_back(std::move(token));
  }

  return std::accumulate(words.begin(), words.end(), std::string(),[](const std::string& a, const std::string& b) -> std::string {
    return a.empty() ? b : a+ ' ' + b;
  });

}

int main(){

  std::string encoded_message = ".... . -.--   .--- ..- -.. .";
  std::string decoded_message = decode_morse(encoded_message);
  std::cout << decoded_message << std::endl;

  return 0;
}