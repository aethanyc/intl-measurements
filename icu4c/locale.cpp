#include <unicode/locid.h>
#include <unicode/utypes.h>
#include <unicode/bytestream.h>
#include <stdio.h>
#include <chrono>
#include <vector>
#include <cstring>

using namespace std;

#define NUM(a) (sizeof(a) / sizeof(*a))

static void show(void);

void show(void)
{
  const char* langids[] = {
    "en-US",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en-US",
    "sl",
    "sk",
    "ur",
    "pa-IN",
    "mai",
    "kab",
    "uz",
    "pl",
    "vi",
    "he",
    "bn-BD",
    "ms",
    "ne-NP",
    "km",
    "be",
    "da",
    "sv-SE",
    "gn",
    "kk",
    "mr",
    "mn",
    "pt-BR",
    "ja",
    "el",
    "it",
    "ca",
    "zh-TW",
    "nb-NO",
    "cs",
    "ia",
    "te",
    "pt-PT",
    "ach",
    "ru",
    "hi-IN",
    "tl",
    "ro",
    "hsb",
    "zh-CN",
    "cak",
    "hy-AM",
    "gu-IN",
    "su",
    "uk",
    "sr",
    "si",
    "ga-IE",
    "ml",
    "es-MX",
    "mk",
    "lij",
    "kn",
    "bs",
    "my",
    "ar",
    "gl",
    "hr",
    "hu",
    "nl",
    "bg",
    "es-AR",
    "ast",
    "ka",
    "de",
    "az",
    "gd",
    "br",
    "ko",
    "fi",
    "es-CL",
    "crh",
    "eo",
    "id",
    "fr",
    "et",
    "fa",
    "nn-NO",
    "lt",
    "ff",
    "cy",
    "es-ES",
    "eu",
    "lo",
    "rm",
    "dsb",
    "ta",
    "th",
    "tr",
    "fy-NL",
    "sq",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en-us",
    "en_Latn_US",
    "en-us",
    "en_Latn_US",
    "en-us",
    "en_Latn_US",
    "en-us",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en-us",
    "en_Latn_US",
    "en-us",
    "en_Latn_US",
    "en",
    "en-US",
    "en",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en-us",
    "en_Latn_US",
    "en",
    "en-US",
    "en",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en",
    "be",
    "ch",
    "it",
    "ca",
    "uk",
    "au",
    "nl",
    "at",
    "de",
    "fr",
    "es",
    "ie",
    "en-US",
    "be",
    "ch",
    "it",
    "ca",
    "uk",
    "ta",
    "au",
    "ta_Taml_IN",
    "nl",
    "pl",
    "at",
    "pl_Latn_PL",
    "de",
    "es-es",
    "fr",
    "es_Latn_ES",
    "es",
    "en",
    "ie",
    "en-US",
    "hr",
    "en_Latn_US",
    "hr_Latn_HR",
    "en_Latn_US",
    "tr",
    "tr_Latn_TR",
    "hi-in",
    "hi_Deva_IN",
    "ja",
    "ja_Jpan_JP",
    "es-mx",
    "es_Latn_MX",
    "it",
    "it_Latn_IT",
    "zh-tw",
    "zh_Hant_TW",
    "mk",
    "mk_Cyrl_MK",
    "en-us",
    "en_Latn_US",
    "zh-cn",
    "zh_Hans_CN",
    "pt-br",
    "pt_Latn_BR",
    "id",
    "id_Latn_ID",
    "en",
    "en_Latn_US",
    "fr",
    "fr_Latn_FR",
    "cs",
    "cs_Latn_CZ",
    "hu",
    "hu_Latn_HU",
    "nl",
    "nl_Latn_NL",
    "ro",
    "ro_Latn_RO",
    "el",
    "el_Grek_GR",
    "sr",
    "sr_Cyrl_RS",
    "bn",
    "bn_Beng_BD",
    "de",
    "de_Latn_DE",
    "ru",
    "ru_Cyrl_RU",
    "en",
    "en_Latn_US",
    "be",
    "ch",
    "it",
    "ca",
    "uk",
    "au",
    "nl",
    "at",
    "de",
    "fr",
    "es",
    "en",
    "ie",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en",
    "ja",
    "en-US",
    "ja",
    "en",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "ja",
    "en",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "bn",
    "bn_Beng_BD",
    "cs",
    "cs_Latn_CZ",
    "sl",
    "sk",
    "ur",
    "pa-IN",
    "mai",
    "kab",
    "uz",
    "pl",
    "vi",
    "sq",
    "bn-BD",
    "he",
    "ms",
    "en-US",
    "km",
    "ne-NP",
    "be",
    "da",
    "sv-SE",
    "gn",
    "mr",
    "kk",
    "mn",
    "pt-BR",
    "ja",
    "el",
    "it",
    "ca",
    "zh-TW",
    "nb-NO",
    "cs",
    "ia",
    "te",
    "pt-PT",
    "ach",
    "ru",
    "tl",
    "hi-IN",
    "ro",
    "hsb",
    "zh-CN",
    "cak",
    "hy-AM",
    "gu-IN",
    "su",
    "uk",
    "sr",
    "ga-IE",
    "si",
    "ml",
    "es-MX",
    "mk",
    "lij",
    "kn",
    "bs",
    "my",
    "ar",
    "gl",
    "hr",
    "hu",
    "nl",
    "bg",
    "es-AR",
    "ast",
    "ka",
    "de",
    "az",
    "gd",
    "br",
    "ko",
    "fi",
    "es-CL",
    "crh",
    "eo",
    "id",
    "fr",
    "et",
    "fa",
    "nn-NO",
    "lt",
    "ff",
    "cy",
    "es-ES",
    "eu",
    "lo",
    "rm",
    "dsb",
    "ta",
    "th",
    "tr",
    "fy-NL",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "el",
    "el_Grek_GR",
    "hi-IN",
    "hi_Deva_IN",
    "sl",
    "sk",
    "ur",
    "pa-IN",
    "mai",
    "kab",
    "uz",
    "pl",
    "vi",
    "sq",
    "bn-BD",
    "he",
    "ms",
    "en-US",
    "km",
    "ne-NP",
    "be",
    "da",
    "sv-SE",
    "gn",
    "mr",
    "kk",
    "mn",
    "pt-BR",
    "ja",
    "el",
    "it",
    "ca",
    "zh-TW",
    "nb-NO",
    "cs",
    "ia",
    "te",
    "pt-PT",
    "ach",
    "ru",
    "tl",
    "hi-IN",
    "ro",
    "hsb",
    "zh-CN",
    "cak",
    "hy-AM",
    "gu-IN",
    "su",
    "uk",
    "sr",
    "ga-IE",
    "si",
    "ml",
    "es-MX",
    "mk",
    "lij",
    "kn",
    "bs",
    "my",
    "ar",
    "gl",
    "hr",
    "hu",
    "nl",
    "bg",
    "es-AR",
    "ast",
    "ka",
    "de",
    "az",
    "gd",
    "br",
    "ko",
    "fi",
    "es-CL",
    "crh",
    "eo",
    "id",
    "fr",
    "et",
    "fa",
    "nn-NO",
    "lt",
    "ff",
    "cy",
    "es-ES",
    "eu",
    "lo",
    "rm",
    "dsb",
    "ja",
    "ta",
    "ja_Jpan_JP",
    "th",
    "tr",
    "fy-NL",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "mk",
    "mk_Cyrl_MK",
    "ro",
    "ro_Latn_RO",
    "ru",
    "ru_Cyrl_RU",
    "sr",
    "sr_Cyrl_RS",
    "ta",
    "ta_Taml_IN",
    "zh-CN",
    "zh_Hans_CN",
    "zh-TW",
    "zh_Hant_TW",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "bn",
    "bn_Beng_BD",
    "cs",
    "cs_Latn_CZ",
    "el",
    "el_Grek_GR",
    "hi-IN",
    "hi_Deva_IN",
    "ja",
    "ja_Jpan_JP",
    "mk",
    "mk_Cyrl_MK",
    "ro",
    "ro_Latn_RO",
    "ru",
    "ru_Cyrl_RU",
    "sr",
    "sr_Cyrl_RS",
    "ta",
    "ta_Taml_IN",
    "zh-CN",
    "zh_Hans_CN",
    "zh-TW",
    "zh_Hant_TW",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "en_Latn_US",
    "en",
    "sl",
    "ur",
    "fy-NL",
    "kab",
    "uz",
    "pl",
    "vi",
    "sq",
    "he",
    "ms",
    "km",
    "hy",
    "NN",
    "be",
    "kk",
    "gn",
    "mr",
    "NO",
    "ja",
    "lv",
    "oc",
    "it",
    "ca",
    "is",
    "ia",
    "cz",
    "ru",
    "tl",
    "ro",
    "be-tarask",
    "hsb",
    "zh-CN",
    "pt",
    "uk",
    "sr",
    "ltg",
    "pa",
    "si",
    "ml",
    "kr",
    "mk",
    "an",
    "lij",
    "kn",
    "bs",
    "zh-TW",
    "ka",
    "de",
    "as",
    "az",
    "gd",
    "br",
    "fi",
    "crh",
    "eo",
    "id",
    "fr",
    "sv-SE",
    "es",
    "et",
    "fa",
    "lt",
    "or",
    "cy",
    "eu",
    "lo",
    "tr",
    "wo",
    "sk",
    "da",
    "gu",
    "el",
    "te",
    "ga-IE",
    "my",
    "ar",
    "gl",
    "hr",
    "hu",
    "nl",
    "bg",
    "bn",
    "ne",
    "ast",
    "af",
    "hi",
    "rm",
    "dsb",
    "ta",
    "th",
    "en-US",
    "sl",
    "sk",
    "ur",
    "fy-NL",
    "kab",
    "uz",
    "pl",
    "vi",
    "sq",
    "he",
    "ms",
    "km",
    "hy",
    "NN",
    "be",
    "da",
    "gn",
    "mr",
    "kk",
    "NO",
    "gu",
    "ja",
    "el",
    "lv",
    "oc",
    "it",
    "ca",
    "is",
    "ia",
    "cz",
    "te",
    "ga-IE",
    "ru",
    "tl",
    "ro",
    "be-tarask",
    "hsb",
    "zh-CN",
    "pt",
    "uk",
    "sr",
    "ltg",
    "pa",
    "si",
    "ml",
    "kr",
    "mk",
    "an",
    "lij",
    "kn",
    "bs",
    "zh-TW",
    "my",
    "ar",
    "gl",
    "hr",
    "hu",
    "nl",
    "bg",
    "bn",
    "ne",
    "ast",
    "af",
    "hi",
    "ka",
    "de",
    "as",
    "az",
    "gd",
    "br",
    "fi",
    "crh",
    "eo",
    "id",
    "fr",
    "sv-SE",
    "es",
    "et",
    "en",
    "fa",
    "lt",
    "or",
    "cy",
    "eu",
    "lo",
    "rm",
    "dsb",
    "ta",
    "th",
    "tr",
    "wo",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "sl",
    "sk",
    "ur",
    "fy-NL",
    "kab",
    "uz",
    "pl",
    "vi",
    "sq",
    "he",
    "ms",
    "km",
    "hy",
    "NN",
    "be",
    "da",
    "gn",
    "mr",
    "kk",
    "NO",
    "gu",
    "ja",
    "el",
    "lv",
    "oc",
    "it",
    "ca",
    "is",
    "ia",
    "cz",
    "te",
    "ga-IE",
    "ru",
    "tl",
    "ro",
    "be-tarask",
    "hsb",
    "zh-CN",
    "pt",
    "uk",
    "sr",
    "ltg",
    "pa",
    "si",
    "ml",
    "kr",
    "mk",
    "an",
    "lij",
    "kn",
    "bs",
    "zh-TW",
    "my",
    "ar",
    "gl",
    "hr",
    "hu",
    "nl",
    "bg",
    "bn",
    "ne",
    "ast",
    "af",
    "hi",
    "ka",
    "de",
    "as",
    "az",
    "gd",
    "br",
    "fi",
    "crh",
    "eo",
    "id",
    "fr",
    "sv-SE",
    "es",
    "et",
    "en",
    "fa",
    "lt",
    "or",
    "cy",
    "eu",
    "lo",
    "rm",
    "dsb",
    "ta",
    "th",
    "tr",
    "wo",
    "en-US",
    "en_Latn_US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-us",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-us",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
    "en-US",
    "en_Latn_US",
  };

  {
    // Construct
    auto start = chrono::steady_clock::now();

    for (auto& langid : langids) {
      icu::Locale aLocale = icu::Locale(langid);
    }
    
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    auto measured_us = chrono::duration_cast<chrono::microseconds>(diff).count();
    printf("Create Locale from str for %lu locales. time: %lld us\n", NUM(langids), measured_us);

  }

  vector<icu::Locale> locales;

  {
    // Compare
    icu::Locale referenceLocale = icu::Locale("en-US");

    for (auto& id : langids) {
      icu::Locale aLocale = icu::Locale(id);
      locales.push_back(aLocale);
    }

    unsigned int matches = 0;

    auto start = chrono::steady_clock::now();

    for (auto& loc : locales) {
      if (loc == referenceLocale) {
        matches += 1;
      }
    }
    
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    auto measured_ns = chrono::duration_cast<chrono::nanoseconds>(diff).count();
    printf("Number of matches against en-US: %d. time: %lld ns\n", matches, measured_ns);
  }

  {
    // Size

    // XXX: We suspect that this does not measure heap allocation, leaving `variants` not accounted for.
    // Since there are only 3 locales with variants in the sample, we hope the results
    // remain meaningful, but it would be nice to improve the measuring.

    unsigned int size = sizeof(decltype(locales.back())) * locales.capacity();
    printf("Total size of the locales vector: %d bytes.\n", size);
  }

  {
    // ToString

    UErrorCode status = U_ZERO_ERROR;

    auto start = chrono::steady_clock::now();

    for (auto& loc : locales) {
      string dest = "";
      icu::StringByteSink<std::string> sink(&dest);
      loc.toLanguageTag(sink, status);
    }
    
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    auto measured_us = chrono::duration_cast<chrono::microseconds>(diff).count();
    printf("Serialized Locale. time: %lld us\n", measured_us);
  }
}


int main() {
  show();
  return 0;
}