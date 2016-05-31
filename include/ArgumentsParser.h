#ifndef __ARGUMENTSPARSER_H__
#define __ARGUMENTSPARSER_H__

#include "CommonIncludes.h"

class ArgumentsParser
{
  private:
    ArgumentsParser();
    ~ArgumentsParser();

    void showHelpAndExit();
    
    int _argc;
    char ** _argv;
    std::set<std::string> _opts;

    static ArgumentsParser * _instance;

  public:
    static ArgumentsParser * instance();
    static void nullify();

    void init(int, char **);

    int getArgc();
    char ** getArgv();
    bool get(std::string);
};

#endif  // __ARGUMENTSPARSER_H__
