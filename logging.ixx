module;

#include <memory>
#include <stdarg.h>

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include <spdlog/spdlog.h>

export module logging;

class Logging {
public:
  static std::shared_ptr<spdlog::logger> GetLogger() {
    static Logging logging;
    return logging._coreLogger;
  }

  Logging( Logging const& )        = delete;
  void operator=( Logging const& ) = delete;

private:
  Logging() {
    this->_coreLogger = spdlog::stdout_color_mt( "CORE" );
    this->_coreLogger->set_level( spdlog::level::trace );
  }

  std::shared_ptr<spdlog::logger> _coreLogger;
};

export template <typename... Args>
void Error( Args... kwargs ) {
  Logging::GetLogger()->error( kwargs... );
}

export template <typename... Args>
void Warn( Args... kwargs ) {
  Logging::GetLogger()->warn( kwargs... );
}

export template <typename... Args>
void Debug( Args... kwargs ) {
  Logging::GetLogger()->debug( kwargs... );
}

export template <typename... Args>
void Info( Args... kwargs ) {
  Logging::GetLogger()->info( kwargs... );
}

export template <typename... Args>
void Trace( Args... kwargs ) {
  Logging::GetLogger()->trace( kwargs... );
}