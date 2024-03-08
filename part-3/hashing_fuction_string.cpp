// B16 sheet # 3 - Question 8.3

#include <iostream>
#include <cstdint>


uint32_t hash(const std::string& str, const uint32_t m)
{
    uint32_t hash = 0;
    for (char c : str) {
        hash = (hash * 256 + c) % m;     // Based on the property: a + b mod m = ((a mod m) + (b mod m)) mod m
    }
    return hash;
}

void test_invariance(uint32_t m) {
for (const auto& key : {"ciao", "icao", "iaco", "iaoc", "caio", "acio"}) {
std::cout << "h(\"" << key << "\", " << m
<< ") = " << hash(key, m) << '\n';

}
}

int main(int argc, char** argv) {
    const uint32_t m = 255;
    std::string key{"ciao"};
    std::cout << "h(\"" << key << "\") = " << hash(key, m) << '\n';
    std::string key2{"oaic"};
    std::cout << "h(\"" << key2 << "\") = " << hash(key2, m) << '\n';
    auto key_as_integer =
    (static_cast<uint32_t>(key[0]) << 24) +
    (static_cast<uint32_t>(key[1]) << 16) +
    (static_cast<uint32_t>(key[2]) << 8) +
    (static_cast<uint32_t>(key[3]) << 0);
    std::cout << key_as_integer << " % " << m
    << " = " << (key_as_integer % m) << '\n';

    test_invariance(255); // invariant
    test_invariance(254); // not invariant


    return 0;
}

