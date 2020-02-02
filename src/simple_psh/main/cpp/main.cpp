#define SIMPLEPSH_MODULE_EXPORT

#include <simplepsh.hpp>

#include <cstdlib>
#include <memory>
#include <simple_psh/main/headers/noopinterpreter.hpp>

class PSH;

int main(int argc, char **argv) {
    std::unique_ptr<Interpreter> interpreter(new NoOpInterpreter());
    std::unique_ptr<PSH> psh(new SimplePSH(std::move(interpreter)));
    psh->initialize();
    psh->execute();
    psh->terminate();
    return EXIT_SUCCESS;
}