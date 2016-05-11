#include "ArgumentsParser.h"

#include "Utils.h"

void
ArgumentsParser::showHelpAndExit()
{
  std::cout << "usage: " << getArgv()[0] << " [--console] [--beginner]" << std::endl;
  std::cout << std::endl;
  std::cout << "    [--console]    select console based game; default is gui based" << std::endl;
  std::cout << "    [--beginner]   select beginner level difficulty; default is expert" << std::endl;

  exit(0);
}

ArgumentsParser::ArgumentsParser()
{
}

void
ArgumentsParser::init(int argc, char **argv)
{
  _argc = argc;
  _argv = argv;

  for (int i = 1; i < argc; ++i)
  {
    std::string stripped(argv[i]);
    stripped = stripped.substr(2);

    if ( DEBUG )
      std::cerr << "opt: " << stripped << std::endl;

    if (stripped == "help")
    {
      showHelpAndExit();
    }

    _opts.insert(stripped);
  }
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

bool
ArgumentsParser::get(std::string opt)
{
  bool ret = _opts.count(opt) != 0;

  if ( DEBUG )
    std::cerr << "get: " << opt << " -> " << ret << std::endl;

  return ret;
}
