module;

#include <memory>

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include <spdlog/spdlog.h>

export module logging;

class LoggingInstanceManager {
public:
  static std::shared_ptr<spdlog::logger> GetLogger() {
    // Singleton
    static LoggingInstanceManager loggingInstanceManager;
    return loggingInstanceManager._coreLogger;
  }

  LoggingInstanceManager( LoggingInstanceManager const& )        = delete;
  void operator=( LoggingInstanceManager const& ) = delete;

private:
  LoggingInstanceManager() {
    this->_coreLogger = spdlog::stdout_color_mt( "CORE" );
    this->_coreLogger->set_level( spdlog::level::trace );
  }

  std::shared_ptr<spdlog::logger> _coreLogger;
};

export template <typename... Args>
void Error( Args... kwargs ) {
  LoggingInstanceManager::GetLogger()->error( kwargs... );
}

export template <typename... Args>
void Warn( Args... kwargs ) {
  LoggingInstanceManager::GetLogger()->warn( kwargs... );
}

export template <typename... Args>
void Debug( Args... kwargs ) {
  LoggingInstanceManager::GetLogger()->debug( kwargs... );
}

export template <typename... Args>
void Info( Args... kwargs ) {
  LoggingInstanceManager::GetLogger()->info( kwargs... );
}

export template <typename... Args>
void Trace( Args... kwargs ) {
  LoggingInstanceManager::GetLogger()->trace( kwargs... );
}