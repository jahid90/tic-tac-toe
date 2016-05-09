#include "ArgumentsParser.h"

ArgumentsParser::ArgumentsParser()
{
}

void
ArgumentsParser::init(int argc, char **argv)
{
  _argc = argc;
  _argv = argv;
}

int
ArgumentsParser::getArgc()
{
  return _argc;
}

char **
ArgumentsParser::getArgv()
{
  return _argv;
}

std::string
ArgumentsParser::get(char)
{
  // TODO - return value indexed by key from arguments passed to program

  return "";
}
