#ifndef __ARGUMENTSPARSER_H__
#define __ARGUMENTSPARSER_H__

#include "CommonIncludes.h"

class ArgumentsParser
{
  private:
    ArgumentsParser();
    
    int _argc;
    char ** _argv;

  public:
    static ArgumentsParser * instance()
    {
      static ArgumentsParser instance;

      return &instance;
    }

    void init(int, char **);

    int getArgc();
    char ** getArgv();
    std::string get(char);
};

#endif  // __ARGUMENTSPARSER_H__
