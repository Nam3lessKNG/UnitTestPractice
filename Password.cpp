#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string phrase){
  int index = 0;
  bool upper = false;
  bool lower = false;
  while( index < phrase.length()-1 ){
    if(phrase[index] >= 'A' && phrase[index] <= 'Z'){
      upper = true;
    }
    else if(phrase[index] >= 'a' && phrase[index] <= 'z'){
      lower = true;
    }
  }

  if(upper && lower){
    return true;
  }
  return false;
}

Password::Password(){
  pass_history.clear();
  pass_history.push_back("ChicoCA-95929");
}

void Password::set(string phrase){
  // DDigimon
  //The password is at least 8 letters long, but no longer than 20
  if(phrase.length() >= 8 && phrase.length() <= 20){
    //It has no more than 3 of the same leading characters
    if(count_leading_characters(phrase) <= 3){
      //It has mixed case (at least one upper case and at least one lower case)
      if(has_mixed_case(phrase)){
        //It was not a previous password in the history
        if(phrase != pass_history.at(0)){
          pass_history.clear();
          pass_history.push_back(phrase);
        }
      }
    }
  }
}

bool Password::authenticate(string phrase){
  if(phrase == pass_history.at(0)){
    return true;
  }
  return false;
}