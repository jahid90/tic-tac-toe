#include "ArgumentsParser.h"

#include "Utils.h"

ArgumentsParser * ArgumentsParser::_instance = NULL;

ArgumentsParser * ArgumentsParser::instance()
{
  if ( NULL == _instance )
  {
    _instance = new ArgumentsParser;
  }

  return _instance;
}

void
ArgumentsParser::showHelpAndExit()
{
  std::cout << "usage: " << getArgv()[0] << " [--console | --graphical] [--beginner | --expert]" << std::endl;
  std::cout << std::endl;
  std::cout << "    [--console]      select console view based game; default is gui based" << std::endl;
  std::cout << "    [--gui]          select gui view based game; default is gui based" << std::endl;
  std::cout << "    [--beginner]     select beginner level difficulty; default is expert" << std::endl;
  std::cout << "    [--expert]       select expert level difficulty; default is expert" << std::endl;

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

  if ( get("console") && get("gui") )
  {
    std::cout << "only one of --console and --gui switches allowed!" << std::endl;
    std::cout << std::endl;
    showHelpAndExit();
  }

  if ( get("beginner") && get("expert") )
  {
    std::cout << "only one of --beginner and --expert switches allowed!" << std::endl;
    std::cout << std::endl;
    showHelpAndExit();
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
