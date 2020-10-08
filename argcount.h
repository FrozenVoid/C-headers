#pragma once
/* argcount.h macros
argcount(...) count arguments min=0 max=1024
isarg(...) quick check if there an argument(first argument exists)
first(...) return first argument
rest(...) return arguments after first argument.(a,args..)--> args
*/

    #define argcount_count1(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31,_32,_33,_34,_35,_36,_37,_38,_39,_40,_41,_42,_43,_44,_45,_46,_47,_48,_49,_50,_51,_52,_53,_54,_55,_56,_57,_58,_59,_60,_61,_62,_63,_64,_65,_66,_67,_68,_69,_70,_71,_72,_73,_74,_75,_76,_77,_78,_79,_80,_81,_82,_83,_84,_85,_86,_87,_88,_89,_90,_91,_92,_93,_94,_95,_96,_97,_98,_99,_100,_101,_102,_103,_104,_105,_106,_107,_108,_109,_110,_111,_112,_113,_114,_115,_116,_117,_118,_119,_120,_121,_122,_123,_124,_125,_126,_127,_128,_129,_130,_131,_132,_133,_134,_135,_136,_137,_138,_139,_140,_141,_142,_143,_144,_145,_146,_147,_148,_149,_150,_151,_152,_153,_154,_155,_156,_157,_158,_159,_160,_161,_162,_163,_164,_165,_166,_167,_168,_169,_170,_171,_172,_173,_174,_175,_176,_177,_178,_179,_180,_181,_182,_183,_184,_185,_186,_187,_188,_189,_190,_191,_192,_193,_194,_195,_196,_197,_198,_199,_200,_201,_202,_203,_204,_205,_206,_207,_208,_209,_210,_211,_212,_213,_214,_215,_216,_217,_218,_219,_220,_221,_222,_223,_224,_225,_226,_227,_228,_229,_230,_231,_232,_233,_234,_235,_236,_237,_238,_239,_240,_241,_242,_243,_244,_245,_246,_247,_248,_249,_250,_251,_252,_253,_254,_255,_256,_257,_258,_259,_260,_261,_262,_263,_264,_265,_266,_267,_268,_269,_270,_271,_272,_273,_274,_275,_276,_277,_278,_279,_280,_281,_282,_283,_284,_285,_286,_287,_288,_289,_290,_291,_292,_293,_294,_295,_296,_297,_298,_299,_300,_301,_302,_303,_304,_305,_306,_307,_308,_309,_310,_311,_312,_313,_314,_315,_316,_317,_318,_319,_320,_321,_322,_323,_324,_325,_326,_327,_328,_329,_330,_331,_332,_333,_334,_335,_336,_337,_338,_339,_340,_341,_342,_343,_344,_345,_346,_347,_348,_349,_350,_351,_352,_353,_354,_355,_356,_357,_358,_359,_360,_361,_362,_363,_364,_365,_366,_367,_368,_369,_370,_371,_372,_373,_374,_375,_376,_377,_378,_379,_380,_381,_382,_383,_384,_385,_386,_387,_388,_389,_390,_391,_392,_393,_394,_395,_396,_397,_398,_399,_400,_401,_402,_403,_404,_405,_406,_407,_408,_409,_410,_411,_412,_413,_414,_415,_416,_417,_418,_419,_420,_421,_422,_423,_424,_425,_426,_427,_428,_429,_430,_431,_432,_433,_434,_435,_436,_437,_438,_439,_440,_441,_442,_443,_444,_445,_446,_447,_448,_449,_450,_451,_452,_453,_454,_455,_456,_457,_458,_459,_460,_461,_462,_463,_464,_465,_466,_467,_468,_469,_470,_471,_472,_473,_474,_475,_476,_477,_478,_479,_480,_481,_482,_483,_484,_485,_486,_487,_488,_489,_490,_491,_492,_493,_494,_495,_496,_497,_498,_499,_500,_501,_502,_503,_504,_505,_506,_507,_508,_509,_510,_511,_512,_513,_514,_515,_516,_517,_518,_519,_520,_521,_522,_523,_524,_525,_526,_527,_528,_529,_530,_531,_532,_533,_534,_535,_536,_537,_538,_539,_540,_541,_542,_543,_544,_545,_546,_547,_548,_549,_550,_551,_552,_553,_554,_555,_556,_557,_558,_559,_560,_561,_562,_563,_564,_565,_566,_567,_568,_569,_570,_571,_572,_573,_574,_575,_576,_577,_578,_579,_580,_581,_582,_583,_584,_585,_586,_587,_588,_589,_590,_591,_592,_593,_594,_595,_596,_597,_598,_599,_600,_601,_602,_603,_604,_605,_606,_607,_608,_609,_610,_611,_612,_613,_614,_615,_616,_617,_618,_619,_620,_621,_622,_623,_624,_625,_626,_627,_628,_629,_630,_631,_632,_633,_634,_635,_636,_637,_638,_639,_640,_641,_642,_643,_644,_645,_646,_647,_648,_649,_650,_651,_652,_653,_654,_655,_656,_657,_658,_659,_660,_661,_662,_663,_664,_665,_666,_667,_668,_669,_670,_671,_672,_673,_674,_675,_676,_677,_678,_679,_680,_681,_682,_683,_684,_685,_686,_687,_688,_689,_690,_691,_692,_693,_694,_695,_696,_697,_698,_699,_700,_701,_702,_703,_704,_705,_706,_707,_708,_709,_710,_711,_712,_713,_714,_715,_716,_717,_718,_719,_720,_721,_722,_723,_724,_725,_726,_727,_728,_729,_730,_731,_732,_733,_734,_735,_736,_737,_738,_739,_740,_741,_742,_743,_744,_745,_746,_747,_748,_749,_750,_751,_752,_753,_754,_755,_756,_757,_758,_759,_760,_761,_762,_763,_764,_765,_766,_767,_768,_769,_770,_771,_772,_773,_774,_775,_776,_777,_778,_779,_780,_781,_782,_783,_784,_785,_786,_787,_788,_789,_790,_791,_792,_793,_794,_795,_796,_797,_798,_799,_800,_801,_802,_803,_804,_805,_806,_807,_808,_809,_810,_811,_812,_813,_814,_815,_816,_817,_818,_819,_820,_821,_822,_823,_824,_825,_826,_827,_828,_829,_830,_831,_832,_833,_834,_835,_836,_837,_838,_839,_840,_841,_842,_843,_844,_845,_846,_847,_848,_849,_850,_851,_852,_853,_854,_855,_856,_857,_858,_859,_860,_861,_862,_863,_864,_865,_866,_867,_868,_869,_870,_871,_872,_873,_874,_875,_876,_877,_878,_879,_880,_881,_882,_883,_884,_885,_886,_887,_888,_889,_890,_891,_892,_893,_894,_895,_896,_897,_898,_899,_900,_901,_902,_903,_904,_905,_906,_907,_908,_909,_910,_911,_912,_913,_914,_915,_916,_917,_918,_919,_920,_921,_922,_923,_924,_925,_926,_927,_928,_929,_930,_931,_932,_933,_934,_935,_936,_937,_938,_939,_940,_941,_942,_943,_944,_945,_946,_947,_948,_949,_950,_951,_952,_953,_954,_955,_956,_957,_958,_959,_960,_961,_962,_963,_964,_965,_966,_967,_968,_969,_970,_971,_972,_973,_974,_975,_976,_977,_978,_979,_980,_981,_982,_983,_984,_985,_986,_987,_988,_989,_990,_991,_992,_993,_994,_995,_996,_997,_998,_999,_1000,_1001,_1002,_1003,_1004,_1005,_1006,_1007,_1008,_1009,_1010,_1011,_1012,_1013,_1014,_1015,_1016,_1017,_1018,_1019,_1020,_1021,_1022,_1023,_1024,_1025,N,...) N
    #define argcount_count(args...) argcount_count1(args) 
    //  args push>>> n. 3,2,1 :: :args:<numbers> 
    #define argcount(...) argcount_count(0,##__VA_ARGS__,1025,1024,1023,1022,1021,1020,1019,1018,1017,1016,1015,1014,1013,1012,1011,1010,1009,1008,1007,1006,1005,1004,1003,1002,1001,1000,999,998,997,996,995,994,993,992,991,990,989,988,987,986,985,984,983,982,981,980,979,978,977,976,975,974,973,972,971,970,969,968,967,966,965,964,963,962,961,960,959,958,957,956,955,954,953,952,951,950,949,948,947,946,945,944,943,942,941,940,939,938,937,936,935,934,933,932,931,930,929,928,927,926,925,924,923,922,921,920,919,918,917,916,915,914,913,912,911,910,909,908,907,906,905,904,903,902,901,900,899,898,897,896,895,894,893,892,891,890,889,888,887,886,885,884,883,882,881,880,879,878,877,876,875,874,873,872,871,870,869,868,867,866,865,864,863,862,861,860,859,858,857,856,855,854,853,852,851,850,849,848,847,846,845,844,843,842,841,840,839,838,837,836,835,834,833,832,831,830,829,828,827,826,825,824,823,822,821,820,819,818,817,816,815,814,813,812,811,810,809,808,807,806,805,804,803,802,801,800,799,798,797,796,795,794,793,792,791,790,789,788,787,786,785,784,783,782,781,780,779,778,777,776,775,774,773,772,771,770,769,768,767,766,765,764,763,762,761,760,759,758,757,756,755,754,753,752,751,750,749,748,747,746,745,744,743,742,741,740,739,738,737,736,735,734,733,732,731,730,729,728,727,726,725,724,723,722,721,720,719,718,717,716,715,714,713,712,711,710,709,708,707,706,705,704,703,702,701,700,699,698,697,696,695,694,693,692,691,690,689,688,687,686,685,684,683,682,681,680,679,678,677,676,675,674,673,672,671,670,669,668,667,666,665,664,663,662,661,660,659,658,657,656,655,654,653,652,651,650,649,648,647,646,645,644,643,642,641,640,639,638,637,636,635,634,633,632,631,630,629,628,627,626,625,624,623,622,621,620,619,618,617,616,615,614,613,612,611,610,609,608,607,606,605,604,603,602,601,600,599,598,597,596,595,594,593,592,591,590,589,588,587,586,585,584,583,582,581,580,579,578,577,576,575,574,573,572,571,570,569,568,567,566,565,564,563,562,561,560,559,558,557,556,555,554,553,552,551,550,549,548,547,546,545,544,543,542,541,540,539,538,537,536,535,534,533,532,531,530,529,528,527,526,525,524,523,522,521,520,519,518,517,516,515,514,513,512,511,510,509,508,507,506,505,504,503,502,501,500,499,498,497,496,495,494,493,492,491,490,489,488,487,486,485,484,483,482,481,480,479,478,477,476,475,474,473,472,471,470,469,468,467,466,465,464,463,462,461,460,459,458,457,456,455,454,453,452,451,450,449,448,447,446,445,444,443,442,441,440,439,438,437,436,435,434,433,432,431,430,429,428,427,426,425,424,423,422,421,420,419,418,417,416,415,414,413,412,411,410,409,408,407,406,405,404,403,402,401,400,399,398,397,396,395,394,393,392,391,390,389,388,387,386,385,384,383,382,381,380,379,378,377,376,375,374,373,372,371,370,369,368,367,366,365,364,363,362,361,360,359,358,357,356,355,354,353,352,351,350,349,348,347,346,345,344,343,342,341,340,339,338,337,336,335,334,333,332,331,330,329,328,327,326,325,324,323,322,321,320,319,318,317,316,315,314,313,312,311,310,309,308,307,306,305,304,303,302,301,300,299,298,297,296,295,294,293,292,291,290,289,288,287,286,285,284,283,282,281,280,279,278,277,276,275,274,273,272,271,270,269,268,267,266,265,264,263,262,261,260,259,258,257,256,255,254,253,252,251,250,249,248,247,246,245,244,243,242,241,240,239,238,237,236,235,234,233,232,231,230,229,228,227,226,225,224,223,222,221,220,219,218,217,216,215,214,213,212,211,210,209,208,207,206,205,204,203,202,201,200,199,198,197,196,195,194,193,192,191,190,189,188,187,186,185,184,183,182,181,180,179,178,177,176,175,174,173,172,171,170,169,168,167,166,165,164,163,162,161,160,159,158,157,156,155,154,153,152,151,150,149,148,147,146,145,144,143,142,141,140,139,138,137,136,135,134,133,132,131,130,129,128,127,126,125,124,123,122,121,120,119,118,117,116,115,114,113,112,111,110,109,108,107,106,105,104,103,102,101,100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)

    #define argcount_q1(_0,_1,_2,N,...) N
    #define argcount_qc(args...) argcount_q1(args) 
    //  args push>>> n. 3,2,1 :: :args:<numbers> 
    #define argcountq(...) argcount_qc(0,##__VA_ARGS__,2,1,0)
#define rest(a,args...) args
#define first(a,args...) a
#define isarg1(args...) argcountq(args) 
#define isarg(args...) isarg1(first(args))
