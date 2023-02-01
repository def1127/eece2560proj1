#include <vector>

class lockBox
{

    public:
    int correctLocation(lockBox input);
    int incorrectLocation(lockBox input);
    lockBox();
    lockBox(int n, int m);

    private:
    std::vector<int> combination;

};