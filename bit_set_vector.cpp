#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
class BitSet
{
  private:
    std::vector<bool> _bits;

  public:
    bool get(int pos)
    {
        return pos < _bits.size() && _bits[pos];
    }

    void set(int pos)
    {
        ensure(pos);
        _bits[pos] = true;
    }

    void ensure(int pos)
    {
        if (pos >= _bits.size())
        {
            _bits.resize(pos + 64);
        }
    }

    void unset(int pos)
    {
        ensure(pos);
        _bits[pos] = false;
    }

    void print()
    {
        auto begin{_bits.begin()};
        size_t pos{0};
        while (begin != _bits.end())
        {
            std::cout << pos << ": " << *begin << '\n';
            pos++;
            begin++;
        }
    }
};

int main()
{

    BitSet mybitset{};
    mybitset.set(1);
    mybitset.set(6);
    std::cout << mybitset.get(6);

    std::cout << mybitset.get(1) << std::endl;
    mybitset.print();
    return 0;
}
