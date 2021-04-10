#include <musicpp.hpp>

using namespace mpp;
using namespace mpp::literals;

int main(int const argc, char** const argv)
{
    Config const& config { argc, argv };

    auto const& base_synth
    {
        seq
        (
            make_basic<SINE>(Bezier { 2_C, 20 }),
            bind_front<Volume>(Bezier { 1, 0 }),
            bind_front<Size>(config.sample_rate / 4)
        )
    };

    auto const& click_synth
    {
        seq
        (
            make_basic<SAW>(Bezier { 6_C, 20 }),
            bind_front<Volume>(Bezier { 0.5, 0 }),
            bind_front<Size>(config.sample_rate / 32)
        )
    };

    auto&& input
    {
        Volume
        {
            0.7,
            Mix
            {
                base_synth,
                click_synth,
            }
        }
    };

    return main(input, config);
}
