#include "self_power.hpp"
#include <musicpp.hpp>

using namespace mpp;
using namespace mpp::literals;

int main(int const argc, char** const argv)
{
    Config const& config { argc, argv };

    auto&& self_pow_synth
    {
        seq
        (
            make_basic<SINE>(SelfPower { 100000. }),
            bind_front<Size>(config.sample_rate * 20),
            bind_front<Volume>(0.25)
        )
    };

    mpp::generate_and_write_samples(self_pow_synth, config);
    return 0;
}
