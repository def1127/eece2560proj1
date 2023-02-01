#include <vector>

class lockBox
{

    public:
    int correctLocation(lockBox input);
    int incorrectLocation(lockBox input);
    lockBox();
    lockBox(int n, int m);
    lockBox(std::vector<int> input);

    private:
    std::vector<int> combination;
    std::vector<int> generateCombination(int n, int m);

};