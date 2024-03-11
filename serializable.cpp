#include<string>

using namespace std;

/*
    This is serializable class and it is an abstract class
    Any class derived from this class must implement 'toString' method
*/

class Serializable {
    public:
        virtual string toString() const = 0;
};