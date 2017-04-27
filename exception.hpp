// exception.hpp

#include <exception>
#include <system_error>
#include <future>
#include <iostream>
#include <utility>

namespace util
{
  template <typename T>
  void processCodeException(const T& e)
  {
    auto c = e.code();
    std::cerr << "- category:      " << c.category().name() << std::endl;
    std::cerr << "- value:         " << c.value() << std::endl;
    std::cerr << "- msg:           " << c.message() << std::endl;
    std::cerr << "- def category:  " 
              << c.default_error_condition().category().name() << std::endl;
    std::cerr << "- def value:     "
              << c.default_error_condition().value() << std::endl;
    std::cerr << "- def msg:       "
              << c.default_error_condition().message() << std::endl;

  }

  void processException()
  {
    try {
      throw; // rethrow exception to deal with it here
    }
    catch (const ios_base::failure& e) {
      cerr << "I/O EXCEPTION: " << e.what() << endl;
      processCodeException(e);
    }
    catch (const system_error& e) {
      cerr << "SYSTEM EXCEPTION: " << e.what() << endl;
      processCodeException(e);
    }
    catch (const future_error& e) {
      cerr << "FUTURE EXCEPTION: " << e.what() << endl;
      processCodeException(e);
    }
    catch (const bad_alloc& e) {
      cerr << "BAD ALLOC EXCEPTION: " << e.what() << endl;
    }
    catch (const exception& e) {
      cerr << "EXCEPTION: " << e.what() << endl;
    }
    catch (...) {
      cerr << "EXCEPTION (unknown)" << endl;
    }
  }

  template <typename T1, typename T2>
  std::ostream& operator << (std::ostream& strm, const std::pair<T1,T2>& p)
  {
    return strm << "[" << p.first << "," << p.second << "]";
  }
}



