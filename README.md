# intl-measurements
Measurements of various intl approaches.

The goal is to measure the performance difference between various reference Internationalization API implementations and ICU4X.

I'll keep this doc with instructions.

# Current results (as of September 17 2020)

Specs:
* Dell XPS 9370 2018, i7-8550U @ 1.8

* **OS**: Ubuntu 20.04
* **C++**: GCC 9.3
* **Rust**: 1.46
* **ICU4C**: 66.1
* **ICU4X**: 0.1

Sample: 956 locale strings provided to MozLocale constructor during fresh-profile startup of Firefox Nightly on Oct 21st 2019.


|                    Test                      |   ICU4C   |    ICU4X  |  Difference |
| -------------------------------------------: | --------: | --------: | ----------: |
| **Locale**  | | | |
| Construct an instance from a string          |    284 us |     33 us |     -88.38% |
| Matching all locales against `en-US`         |  10095 ns |   2085 us |     -79.35% |
| Serializing all locales to a string          |   1186 us |    165 us |     -86.09% |
| Measuring memory allocation of all instances |  229376 b |   30592 b |     -86.66% |
| **PluralRules**  | | | |
|Select 31 numbers for 10 locales              |  421.1 us |  145.1 us |     -65.54% |


# How to run

1) Make sure you have ICU4C installed (some additional settings for homebrew for mac in `icu/macos.txt`)
2) `cd ./icu4c`
3) `make all`
4) `./locale`
5) `./pluralrules`

1) `cd  ../icu4x/locale`
2) `cargo run --release` - for a single-run measurements (like C++), and memory read
3) `cargo bench`  - for statistically valid perf benchmarks
4) `cd ../pluralrules`
5) `cargo run --release` - for a single-run measurements (like C++)

# Limitations

Currently the memory read is suboptimal, but based on review by Adam Gashlin, should be fairly accurate for both C++ and Rust minus `variants`. Since there are only 3 variants in a pool of close to 1000 locales to sample, the results should be fairly accurate.

The `cargo run --release` should be a good 1-1 equivalent of the C++ calls.
