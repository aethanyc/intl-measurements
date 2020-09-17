use std::time::Instant;
use std::convert::TryFrom;
use icu_pluralrules::{PluralRules, PluralRuleType, PluralOperands};
use icu_locale::LanguageIdentifier;
use icu_fs_data_provider::FsDataProvider;

const LANGIDS: &[&str] = &[
    "uk",
    "de",
    "sk",
    "ar",
    "fr",
    "it",
    "en",
    "cs",
    "es",
    "zh"
];
const SAMPLES: &[isize] = &[
    1,
    2,
    3,
    4,
    5,
    25,
    134,
    910293019,
    12,
    1412,
    -12,
    15,
    2931,
    31231,
    3123,
    13231,
    91,
    0,
    231,
    -2,
    -45,
    33,
    728,
    2,
    291,
    24,
    479,
    291,
    778,
    919,
    93
];

fn main() {
    let langids: Vec<LanguageIdentifier> = LANGIDS.iter().map(|s| s.parse().unwrap()).collect();

    let dp = FsDataProvider::try_new("../data/icu4x/json")
        .expect("Loading file from testdata directory");

    let now = Instant::now();

    for langid in &langids {
        let pr = PluralRules::try_new(langid.clone(), PluralRuleType::Cardinal, &dp).unwrap();
        for sample in SAMPLES {
            let operands = PluralOperands::try_from(*sample).unwrap();
            let _ = pr.select(operands);
        }
    }

    let end = now.elapsed().as_nanos();

    println!("Select {} numbers for {} locales: {} ns", SAMPLES.len(), langids.len(), end);
}
