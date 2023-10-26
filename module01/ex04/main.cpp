#include "Replacement.hpp"

int main(int arc, char **arv) {
    if (arc != 4) {
        std::cout << "Number of arguments is not valide" << std::endl;
        return (1);
    }
    Replacement rp(arv[1], arv[2], arv[3]);
    rp.CpyandReplace();
    return (0);
}
