/* Include files */

#include "data_sfun.h"
#include "c4_data.h"
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c4_emlrtMCI = { 122,/* lineNo */
  13,                                  /* colNo */
  "rng",                               /* fName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pName */
};

static emlrtMCInfo c4_b_emlrtMCI = { 158,/* lineNo */
  17,                                  /* colNo */
  "eml_rand_mt19937ar",                /* fName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar.m"/* pName */
};

static emlrtRSInfo c4_emlrtRSI = { 4,  /* lineNo */
  "MATLAB Function3",                  /* fcnName */
  "#data:422"                          /* pathName */
};

static emlrtRSInfo c4_b_emlrtRSI = { 5,/* lineNo */
  "MATLAB Function3",                  /* fcnName */
  "#data:422"                          /* pathName */
};

static emlrtRSInfo c4_c_emlrtRSI = { 6,/* lineNo */
  "MATLAB Function3",                  /* fcnName */
  "#data:422"                          /* pathName */
};

static emlrtRSInfo c4_d_emlrtRSI = { 7,/* lineNo */
  "MATLAB Function3",                  /* fcnName */
  "#data:422"                          /* pathName */
};

static emlrtRSInfo c4_e_emlrtRSI = { 54,/* lineNo */
  "rng",                               /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_f_emlrtRSI = { 113,/* lineNo */
  "rng",                               /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_g_emlrtRSI = { 114,/* lineNo */
  "rng",                               /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_h_emlrtRSI = { 116,/* lineNo */
  "rng",                               /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_i_emlrtRSI = { 118,/* lineNo */
  "rng",                               /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_j_emlrtRSI = { 120,/* lineNo */
  "rng",                               /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_k_emlrtRSI = { 273,/* lineNo */
  "rng",                               /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_l_emlrtRSI = { 275,/* lineNo */
  "rng",                               /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_m_emlrtRSI = { 277,/* lineNo */
  "rng",                               /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_n_emlrtRSI = { 278,/* lineNo */
  "rng",                               /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_o_emlrtRSI = { 26,/* lineNo */
  "eml_rand_mt19937ar_stateful",       /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand_mt19937ar_stateful.m"/* pathName */
};

static emlrtRSInfo c4_p_emlrtRSI = { 69,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar.m"/* pathName */
};

static emlrtRSInfo c4_q_emlrtRSI = { 26,/* lineNo */
  "eml_rand_mcg16807_stateful",        /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand_mcg16807_stateful.m"/* pathName */
};

static emlrtRSInfo c4_r_emlrtRSI = { 49,/* lineNo */
  "eml_rand_mcg16807",                 /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand_mcg16807.m"/* pathName */
};

static emlrtRSInfo c4_s_emlrtRSI = { 123,/* lineNo */
  "randn",                             /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\randn.m"/* pathName */
};

static emlrtRSInfo c4_t_emlrtRSI = { 40,/* lineNo */
  "eml_randn",                         /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_randn.m"/* pathName */
};

static emlrtRSInfo c4_u_emlrtRSI = { 57,/* lineNo */
  "eml_randn",                         /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_randn.m"/* pathName */
};

static emlrtRSInfo c4_v_emlrtRSI = { 41,/* lineNo */
  "eml_rand",                          /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand.m"/* pathName */
};

static emlrtRSInfo c4_w_emlrtRSI = { 43,/* lineNo */
  "eml_rand",                          /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand.m"/* pathName */
};

static emlrtRSInfo c4_x_emlrtRSI = { 45,/* lineNo */
  "eml_rand",                          /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand.m"/* pathName */
};

static emlrtRSInfo c4_y_emlrtRSI = { 21,/* lineNo */
  "eml_rand_shr3cong_stateful",        /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand_shr3cong_stateful.m"/* pathName */
};

static emlrtRSInfo c4_ab_emlrtRSI = { 34,/* lineNo */
  "eml_rand_shr3cong",                 /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand_shr3cong.m"/* pathName */
};

static emlrtRSInfo c4_bb_emlrtRSI = { 125,/* lineNo */
  "eml_rand_shr3cong",                 /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand_shr3cong.m"/* pathName */
};

static emlrtRSInfo c4_cb_emlrtRSI = { 136,/* lineNo */
  "eml_rand_shr3cong",                 /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand_shr3cong.m"/* pathName */
};

static emlrtRSInfo c4_db_emlrtRSI = { 160,/* lineNo */
  "eml_rand_shr3cong",                 /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand_shr3cong.m"/* pathName */
};

static emlrtRSInfo c4_eb_emlrtRSI = { 163,/* lineNo */
  "eml_rand_shr3cong",                 /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand_shr3cong.m"/* pathName */
};

static emlrtRSInfo c4_fb_emlrtRSI = { 21,/* lineNo */
  "eml_rand_mt19937ar_stateful",       /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand_mt19937ar_stateful.m"/* pathName */
};

static emlrtRSInfo c4_gb_emlrtRSI = { 56,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar.m"/* pathName */
};

static emlrtRSInfo c4_hb_emlrtRSI = { 420,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar.m"/* pathName */
};

static emlrtRSInfo c4_ib_emlrtRSI = { 438,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar.m"/* pathName */
};

static emlrtRSInfo c4_jb_emlrtRSI = { 447,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar.m"/* pathName */
};

static emlrtRSInfo c4_kb_emlrtRSI = { 449,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar.m"/* pathName */
};

static emlrtRSInfo c4_lb_emlrtRSI = { 257,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar.m"/* pathName */
};

static emlrtRSInfo c4_mb_emlrtRSI = { 263,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar.m"/* pathName */
};

static emlrtRSInfo c4_nb_emlrtRSI = { 268,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar.m"/* pathName */
};

static emlrtRSInfo c4_ob_emlrtRSI = { 151,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "D:\\Matlab2021\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar.m"/* pathName */
};

static const uint32_T c4_uv[625] = { 5489U, 1301868182U, 2938499221U,
  2950281878U, 1875628136U, 751856242U, 944701696U, 2243192071U, 694061057U,
  219885934U, 2066767472U, 3182869408U, 485472502U, 2336857883U, 1071588843U,
  3418470598U, 951210697U, 3693558366U, 2923482051U, 1793174584U, 2982310801U,
  1586906132U, 1951078751U, 1808158765U, 1733897588U, 431328322U, 4202539044U,
  530658942U, 1714810322U, 3025256284U, 3342585396U, 1937033938U, 2640572511U,
  1654299090U, 3692403553U, 4233871309U, 3497650794U, 862629010U, 2943236032U,
  2426458545U, 1603307207U, 1133453895U, 3099196360U, 2208657629U, 2747653927U,
  931059398U, 761573964U, 3157853227U, 785880413U, 730313442U, 124945756U,
  2937117055U, 3295982469U, 1724353043U, 3021675344U, 3884886417U, 4010150098U,
  4056961966U, 699635835U, 2681338818U, 1339167484U, 720757518U, 2800161476U,
  2376097373U, 1532957371U, 3902664099U, 1238982754U, 3725394514U, 3449176889U,
  3570962471U, 4287636090U, 4087307012U, 3603343627U, 202242161U, 2995682783U,
  1620962684U, 3704723357U, 371613603U, 2814834333U, 2111005706U, 624778151U,
  2094172212U, 4284947003U, 1211977835U, 991917094U, 1570449747U, 2962370480U,
  1259410321U, 170182696U, 146300961U, 2836829791U, 619452428U, 2723670296U,
  1881399711U, 1161269684U, 1675188680U, 4132175277U, 780088327U, 3409462821U,
  1036518241U, 1834958505U, 3048448173U, 161811569U, 618488316U, 44795092U,
  3918322701U, 1924681712U, 3239478144U, 383254043U, 4042306580U, 2146983041U,
  3992780527U, 3518029708U, 3545545436U, 3901231469U, 1896136409U, 2028528556U,
  2339662006U, 501326714U, 2060962201U, 2502746480U, 561575027U, 581893337U,
  3393774360U, 1778912547U, 3626131687U, 2175155826U, 319853231U, 986875531U,
  819755096U, 2915734330U, 2688355739U, 3482074849U, 2736559U, 2296975761U,
  1029741190U, 2876812646U, 690154749U, 579200347U, 4027461746U, 1285330465U,
  2701024045U, 4117700889U, 759495121U, 3332270341U, 2313004527U, 2277067795U,
  4131855432U, 2722057515U, 1264804546U, 3848622725U, 2211267957U, 4100593547U,
  959123777U, 2130745407U, 3194437393U, 486673947U, 1377371204U, 17472727U,
  352317554U, 3955548058U, 159652094U, 1232063192U, 3835177280U, 49423123U,
  3083993636U, 733092U, 2120519771U, 2573409834U, 1112952433U, 3239502554U,
  761045320U, 1087580692U, 2540165110U, 641058802U, 1792435497U, 2261799288U,
  1579184083U, 627146892U, 2165744623U, 2200142389U, 2167590760U, 2381418376U,
  1793358889U, 3081659520U, 1663384067U, 2009658756U, 2689600308U, 739136266U,
  2304581039U, 3529067263U, 591360555U, 525209271U, 3131882996U, 294230224U,
  2076220115U, 3113580446U, 1245621585U, 1386885462U, 3203270426U, 123512128U,
  12350217U, 354956375U, 4282398238U, 3356876605U, 3888857667U, 157639694U,
  2616064085U, 1563068963U, 2762125883U, 4045394511U, 4180452559U, 3294769488U,
  1684529556U, 1002945951U, 3181438866U, 22506664U, 691783457U, 2685221343U,
  171579916U, 3878728600U, 2475806724U, 2030324028U, 3331164912U, 1708711359U,
  1970023127U, 2859691344U, 2588476477U, 2748146879U, 136111222U, 2967685492U,
  909517429U, 2835297809U, 3206906216U, 3186870716U, 341264097U, 2542035121U,
  3353277068U, 548223577U, 3170936588U, 1678403446U, 297435620U, 2337555430U,
  466603495U, 1132321815U, 1208589219U, 696392160U, 894244439U, 2562678859U,
  470224582U, 3306867480U, 201364898U, 2075966438U, 1767227936U, 2929737987U,
  3674877796U, 2654196643U, 3692734598U, 3528895099U, 2796780123U, 3048728353U,
  842329300U, 191554730U, 2922459673U, 3489020079U, 3979110629U, 1022523848U,
  2202932467U, 3583655201U, 3565113719U, 587085778U, 4176046313U, 3013713762U,
  950944241U, 396426791U, 3784844662U, 3477431613U, 3594592395U, 2782043838U,
  3392093507U, 3106564952U, 2829419931U, 1358665591U, 2206918825U, 3170783123U,
  31522386U, 2988194168U, 1782249537U, 1105080928U, 843500134U, 1225290080U,
  1521001832U, 3605886097U, 2802786495U, 2728923319U, 3996284304U, 903417639U,
  1171249804U, 1020374987U, 2824535874U, 423621996U, 1988534473U, 2493544470U,
  1008604435U, 1756003503U, 1488867287U, 1386808992U, 732088248U, 1780630732U,
  2482101014U, 976561178U, 1543448953U, 2602866064U, 2021139923U, 1952599828U,
  2360242564U, 2117959962U, 2753061860U, 2388623612U, 4138193781U, 2962920654U,
  2284970429U, 766920861U, 3457264692U, 2879611383U, 815055854U, 2332929068U,
  1254853997U, 3740375268U, 3799380844U, 4091048725U, 2006331129U, 1982546212U,
  686850534U, 1907447564U, 2682801776U, 2780821066U, 998290361U, 1342433871U,
  4195430425U, 607905174U, 3902331779U, 2454067926U, 1708133115U, 1170874362U,
  2008609376U, 3260320415U, 2211196135U, 433538229U, 2728786374U, 2189520818U,
  262554063U, 1182318347U, 3710237267U, 1221022450U, 715966018U, 2417068910U,
  2591870721U, 2870691989U, 3418190842U, 4238214053U, 1540704231U, 1575580968U,
  2095917976U, 4078310857U, 2313532447U, 2110690783U, 4056346629U, 4061784526U,
  1123218514U, 551538993U, 597148360U, 4120175196U, 3581618160U, 3181170517U,
  422862282U, 3227524138U, 1713114790U, 662317149U, 1230418732U, 928171837U,
  1324564878U, 1928816105U, 1786535431U, 2878099422U, 3290185549U, 539474248U,
  1657512683U, 552370646U, 1671741683U, 3655312128U, 1552739510U, 2605208763U,
  1441755014U, 181878989U, 3124053868U, 1447103986U, 3183906156U, 1728556020U,
  3502241336U, 3055466967U, 1013272474U, 818402132U, 1715099063U, 2900113506U,
  397254517U, 4194863039U, 1009068739U, 232864647U, 2540223708U, 2608288560U,
  2415367765U, 478404847U, 3455100648U, 3182600021U, 2115988978U, 434269567U,
  4117179324U, 3461774077U, 887256537U, 3545801025U, 286388911U, 3451742129U,
  1981164769U, 786667016U, 3310123729U, 3097811076U, 2224235657U, 2959658883U,
  3370969234U, 2514770915U, 3345656436U, 2677010851U, 2206236470U, 271648054U,
  2342188545U, 4292848611U, 3646533909U, 3754009956U, 3803931226U, 4160647125U,
  1477814055U, 4043852216U, 1876372354U, 3133294443U, 3871104810U, 3177020907U,
  2074304428U, 3479393793U, 759562891U, 164128153U, 1839069216U, 2114162633U,
  3989947309U, 3611054956U, 1333547922U, 835429831U, 494987340U, 171987910U,
  1252001001U, 370809172U, 3508925425U, 2535703112U, 1276855041U, 1922855120U,
  835673414U, 3030664304U, 613287117U, 171219893U, 3423096126U, 3376881639U,
  2287770315U, 1658692645U, 1262815245U, 3957234326U, 1168096164U, 2968737525U,
  2655813712U, 2132313144U, 3976047964U, 326516571U, 353088456U, 3679188938U,
  3205649712U, 2654036126U, 1249024881U, 880166166U, 691800469U, 2229503665U,
  1673458056U, 4032208375U, 1851778863U, 2563757330U, 376742205U, 1794655231U,
  340247333U, 1505873033U, 396524441U, 879666767U, 3335579166U, 3260764261U,
  3335999539U, 506221798U, 4214658741U, 975887814U, 2080536343U, 3360539560U,
  571586418U, 138896374U, 4234352651U, 2737620262U, 3928362291U, 1516365296U,
  38056726U, 3599462320U, 3585007266U, 3850961033U, 471667319U, 1536883193U,
  2310166751U, 1861637689U, 2530999841U, 4139843801U, 2710569485U, 827578615U,
  2012334720U, 2907369459U, 3029312804U, 2820112398U, 1965028045U, 35518606U,
  2478379033U, 643747771U, 1924139484U, 4123405127U, 3811735531U, 3429660832U,
  3285177704U, 1948416081U, 1311525291U, 1183517742U, 1739192232U, 3979815115U,
  2567840007U, 4116821529U, 213304419U, 4125718577U, 1473064925U, 2442436592U,
  1893310111U, 4195361916U, 3747569474U, 828465101U, 2991227658U, 750582866U,
  1205170309U, 1409813056U, 678418130U, 1171531016U, 3821236156U, 354504587U,
  4202874632U, 3882511497U, 1893248677U, 1903078632U, 26340130U, 2069166240U,
  3657122492U, 3725758099U, 831344905U, 811453383U, 3447711422U, 2434543565U,
  4166886888U, 3358210805U, 4142984013U, 2988152326U, 3527824853U, 982082992U,
  2809155763U, 190157081U, 3340214818U, 2365432395U, 2548636180U, 2894533366U,
  3474657421U, 2372634704U, 2845748389U, 43024175U, 2774226648U, 1987702864U,
  3186502468U, 453610222U, 4204736567U, 1392892630U, 2471323686U, 2470534280U,
  3541393095U, 4269885866U, 3909911300U, 759132955U, 1482612480U, 667715263U,
  1795580598U, 2337923983U, 3390586366U, 581426223U, 1515718634U, 476374295U,
  705213300U, 363062054U, 2084697697U, 2407503428U, 2292957699U, 2426213835U,
  2199989172U, 1987356470U, 4026755612U, 2147252133U, 270400031U, 1367820199U,
  2369854699U, 2844269403U, 79981964U, 624U };

/* Function Declarations */
static void initialize_c4_data(SFc4_dataInstanceStruct *chartInstance);
static void initialize_params_c4_data(SFc4_dataInstanceStruct *chartInstance);
static void enable_c4_data(SFc4_dataInstanceStruct *chartInstance);
static void disable_c4_data(SFc4_dataInstanceStruct *chartInstance);
static void c4_update_jit_animation_state_c4_data(SFc4_dataInstanceStruct
  *chartInstance);
static void c4_do_animation_call_c4_data(SFc4_dataInstanceStruct *chartInstance);
static void ext_mode_exec_c4_data(SFc4_dataInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_data(SFc4_dataInstanceStruct
  *chartInstance);
static void set_sim_state_c4_data(SFc4_dataInstanceStruct *chartInstance, const
  mxArray *c4_st);
static void sf_gateway_c4_data(SFc4_dataInstanceStruct *chartInstance);
static void mdl_start_c4_data(SFc4_dataInstanceStruct *chartInstance);
static void mdl_terminate_c4_data(SFc4_dataInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c4_data(SFc4_dataInstanceStruct
  *chartInstance);
static void mdl_cleanup_runtime_resources_c4_data(SFc4_dataInstanceStruct
  *chartInstance);
static void initSimStructsc4_data(SFc4_dataInstanceStruct *chartInstance);
static real_T c4_mod(SFc4_dataInstanceStruct *chartInstance, real_T c4_x);
static real_T c4_now(SFc4_dataInstanceStruct *chartInstance);
static real_T c4_b_mod(SFc4_dataInstanceStruct *chartInstance, real_T c4_x);
static void c4_randn(SFc4_dataInstanceStruct *chartInstance, const emlrtStack
                     *c4_sp, real_T c4_r[70]);
static void c4_genrandu(SFc4_dataInstanceStruct *chartInstance, uint32_T c4_s,
  uint32_T *c4_e_state, real_T *c4_r);
static void c4_eml_rand_shr3cong(SFc4_dataInstanceStruct *chartInstance,
  uint32_T c4_e_state[2], uint32_T c4_f_state[2], real_T *c4_r);
static void c4_eml_rand_mt19937ar(SFc4_dataInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, uint32_T c4_e_state[625], uint32_T c4_f_state[625], real_T *
  c4_r);
static void c4_genrand_uint32_vector(SFc4_dataInstanceStruct *chartInstance,
  uint32_T c4_mt[625], uint32_T c4_b_mt[625], uint32_T c4_u[2]);
static void c4_b_genrandu(SFc4_dataInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, uint32_T c4_mt[625], uint32_T c4_b_mt[625], real_T *c4_r);
static real_T c4_sumColumnB(SFc4_dataInstanceStruct *chartInstance, real_T c4_x
  [70], int32_T c4_col);
static void c4_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance, const
  mxArray *c4_b_q, const char_T *c4_identifier, real_T c4_y[7]);
static void c4_b_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance, const
  mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[7]);
static uint32_T c4_c_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance,
  const mxArray *c4_c_method, const char_T *c4_identifier, boolean_T *c4_svPtr);
static uint32_T c4_d_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, boolean_T
  *c4_svPtr);
static void c4_e_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance, const
  mxArray *c4_e_state, const char_T *c4_identifier, boolean_T *c4_svPtr,
  uint32_T c4_y[625]);
static void c4_f_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance, const
  mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, boolean_T *c4_svPtr,
  uint32_T c4_y[625]);
static void c4_g_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance, const
  mxArray *c4_e_state, const char_T *c4_identifier, boolean_T *c4_svPtr,
  uint32_T c4_y[2]);
static void c4_h_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance, const
  mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, boolean_T *c4_svPtr,
  uint32_T c4_y[2]);
static uint8_T c4_i_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_data, const char_T *c4_identifier);
static uint8_T c4_j_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_chart_data_browse_helper(SFc4_dataInstanceStruct *chartInstance,
  int32_T c4_ssIdNumber, const mxArray **c4_mxData, uint8_T *c4_isValueTooBig);
static real_T c4_b_eml_rand_shr3cong(SFc4_dataInstanceStruct *chartInstance,
  uint32_T c4_e_state[2]);
static real_T c4_b_eml_rand_mt19937ar(SFc4_dataInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, uint32_T c4_e_state[625]);
static void c4_b_genrand_uint32_vector(SFc4_dataInstanceStruct *chartInstance,
  uint32_T c4_mt[625], uint32_T c4_u[2]);
static real_T c4_c_genrandu(SFc4_dataInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, uint32_T c4_mt[625]);
static real_T c4_get_a(SFc4_dataInstanceStruct *chartInstance, uint32_T
  c4_elementIndex);
static void c4_set_a(SFc4_dataInstanceStruct *chartInstance, uint32_T
                     c4_elementIndex, real_T c4_elementValue);
static real_T *c4_access_a(SFc4_dataInstanceStruct *chartInstance, uint32_T
  c4_rdOnly);
static real_T c4_get_b(SFc4_dataInstanceStruct *chartInstance, uint32_T
  c4_elementIndex);
static void c4_set_b(SFc4_dataInstanceStruct *chartInstance, uint32_T
                     c4_elementIndex, real_T c4_elementValue);
static real_T *c4_access_b(SFc4_dataInstanceStruct *chartInstance, uint32_T
  c4_rdOnly);
static real_T c4_get_f(SFc4_dataInstanceStruct *chartInstance, uint32_T
  c4_elementIndex);
static void c4_set_f(SFc4_dataInstanceStruct *chartInstance, uint32_T
                     c4_elementIndex, real_T c4_elementValue);
static real_T *c4_access_f(SFc4_dataInstanceStruct *chartInstance, uint32_T
  c4_rdOnly);
static void init_dsm_address_info(SFc4_dataInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc4_dataInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_data(SFc4_dataInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_seed_not_empty = false;
  chartInstance->c4_method_not_empty = false;
  chartInstance->c4_state_not_empty = false;
  chartInstance->c4_b_state_not_empty = false;
  chartInstance->c4_c_state_not_empty = false;
  chartInstance->c4_b_method_not_empty = false;
  chartInstance->c4_d_state_not_empty = false;
  chartInstance->c4_is_active_c4_data = 0U;
}

static void initialize_params_c4_data(SFc4_dataInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_data(SFc4_dataInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_data(SFc4_dataInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_jit_animation_state_c4_data(SFc4_dataInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c4_do_animation_call_c4_data(SFc4_dataInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static void ext_mode_exec_c4_data(SFc4_dataInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_data(SFc4_dataInstanceStruct
  *chartInstance)
{
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_i_y = NULL;
  const mxArray *c4_j_y = NULL;
  const mxArray *c4_k_y = NULL;
  const mxArray *c4_l_y = NULL;
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(11, 1), false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", *chartInstance->c4_q, 0, 0U, 1U, 0U,
    1, 7), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", *chartInstance->c4_qd, 0, 0U, 1U, 0U,
    1, 7), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", *chartInstance->c4_qdd, 0, 0U, 1U,
    0U, 1, 7), false);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_e_y = NULL;
  if (!chartInstance->c4_method_not_empty) {
    sf_mex_assign(&c4_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_e_y, sf_mex_create("y", &chartInstance->c4_method, 7, 0U,
      0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_f_y = NULL;
  if (!chartInstance->c4_method_not_empty) {
    sf_mex_assign(&c4_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_f_y, sf_mex_create("y", &chartInstance->c4_b_method, 7, 0U,
      0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 4, c4_f_y);
  c4_g_y = NULL;
  if (!chartInstance->c4_method_not_empty) {
    sf_mex_assign(&c4_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_g_y, sf_mex_create("y", &chartInstance->c4_seed, 7, 0U, 0U,
      0U, 0), false);
  }

  sf_mex_setcell(c4_y, 5, c4_g_y);
  c4_h_y = NULL;
  if (!chartInstance->c4_method_not_empty) {
    sf_mex_assign(&c4_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_h_y, sf_mex_create("y", &chartInstance->c4_c_state, 7, 0U,
      0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 6, c4_h_y);
  c4_i_y = NULL;
  if (!chartInstance->c4_state_not_empty) {
    sf_mex_assign(&c4_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_i_y, sf_mex_create("y", chartInstance->c4_state, 7, 0U, 1U,
      0U, 1, 625), false);
  }

  sf_mex_setcell(c4_y, 7, c4_i_y);
  c4_j_y = NULL;
  if (!chartInstance->c4_b_state_not_empty) {
    sf_mex_assign(&c4_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_j_y, sf_mex_create("y", chartInstance->c4_b_state, 7, 0U,
      1U, 0U, 1, 2), false);
  }

  sf_mex_setcell(c4_y, 8, c4_j_y);
  c4_k_y = NULL;
  if (!chartInstance->c4_b_state_not_empty) {
    sf_mex_assign(&c4_k_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_k_y, sf_mex_create("y", chartInstance->c4_d_state, 7, 0U,
      1U, 0U, 1, 2), false);
  }

  sf_mex_setcell(c4_y, 9, c4_k_y);
  c4_l_y = NULL;
  sf_mex_assign(&c4_l_y, sf_mex_create("y", &chartInstance->c4_is_active_c4_data,
    3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 10, c4_l_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_data(SFc4_dataInstanceStruct *chartInstance, const
  mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv[7];
  real_T c4_dv1[7];
  real_T c4_dv2[7];
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  uint32_T c4_b_uv[625];
  uint32_T c4_uv1[2];
  uint32_T c4_uv2[2];
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)), "q",
                      c4_dv);
  for (c4_i = 0; c4_i < 7; c4_i++) {
    (*chartInstance->c4_q)[c4_i] = c4_dv[c4_i];
  }

  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)), "qd",
                      c4_dv1);
  for (c4_i1 = 0; c4_i1 < 7; c4_i1++) {
    (*chartInstance->c4_qd)[c4_i1] = c4_dv1[c4_i1];
  }

  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 2)), "qdd",
                      c4_dv2);
  for (c4_i2 = 0; c4_i2 < 7; c4_i2++) {
    (*chartInstance->c4_qdd)[c4_i2] = c4_dv2[c4_i2];
  }

  chartInstance->c4_method = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 3)), "method", &chartInstance->c4_method_not_empty);
  chartInstance->c4_b_method = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 4)), "method", &chartInstance->c4_b_method_not_empty);
  chartInstance->c4_seed = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 5)), "seed", &chartInstance->c4_seed_not_empty);
  chartInstance->c4_c_state = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 6)), "state", &chartInstance->c4_c_state_not_empty);
  c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 7)),
                        "state", &chartInstance->c4_state_not_empty, c4_b_uv);
  for (c4_i3 = 0; c4_i3 < 625; c4_i3++) {
    chartInstance->c4_state[c4_i3] = c4_b_uv[c4_i3];
  }

  c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 8)),
                        "state", &chartInstance->c4_b_state_not_empty, c4_uv1);
  for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
    chartInstance->c4_b_state[c4_i4] = c4_uv1[c4_i4];
  }

  c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 9)),
                        "state", &chartInstance->c4_d_state_not_empty, c4_uv2);
  for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
    chartInstance->c4_d_state[c4_i5] = c4_uv2[c4_i5];
  }

  chartInstance->c4_is_active_c4_data = c4_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 10)), "is_active_c4_data");
  sf_mex_destroy(&c4_u);
  sf_mex_destroy(&c4_st);
}

static void sf_gateway_c4_data(SFc4_dataInstanceStruct *chartInstance)
{
  static real_T c4_B[7] = { 2.7925268031909272, 2.3561944901923448,
    2.3561944901923448, 2.4434609527920612, 1.7453292519943295,
    4.6425758103049164, 1.7453292519943295 };

  static real_T c4_dv[7] = { 0.0, 1.5707963267948966, -1.5707963267948966,
    0.52359877559829882, 0.0, 0.0, 0.0 };

  static char_T c4_cv[22] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'n', 'g',
    ':', 'b', 'a', 'd', 'S', 'e', 't', 't', 'i', 'n', 'g', 's' };

  time_t c4_b_eTime;
  time_t c4_eTime;
  emlrtStack c4_b_st;
  emlrtStack c4_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  real_T c4_b_y[70];
  real_T c4_c_y[70];
  real_T c4_dv1[70];
  real_T c4_dv2[70];
  real_T c4_dv3[70];
  real_T c4_f_y[70];
  real_T c4_y[70];
  real_T c4_b;
  real_T c4_b_b;
  real_T c4_b_mti;
  real_T c4_b_t;
  real_T c4_b_x;
  real_T c4_c_b;
  real_T c4_c_x;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_i_x;
  real_T c4_j_x;
  real_T c4_s;
  real_T c4_s0;
  real_T c4_x;
  int32_T c4_b_col;
  int32_T c4_b_k;
  int32_T c4_c_col;
  int32_T c4_c_k;
  int32_T c4_c_t;
  int32_T c4_col;
  int32_T c4_d_col;
  int32_T c4_d_k;
  int32_T c4_e_col;
  int32_T c4_e_k;
  int32_T c4_exitg1;
  int32_T c4_f_col;
  int32_T c4_f_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_k;
  int32_T c4_mti;
  int32_T c4_prevEpochTime;
  uint32_T c4_arg3;
  uint32_T c4_b_arg3;
  uint32_T c4_b_r;
  uint32_T c4_b_s;
  uint32_T c4_b_seed;
  uint32_T c4_b_varargin_1;
  uint32_T c4_c_arg3;
  uint32_T c4_c_seed;
  uint32_T c4_c_varargin_1;
  uint32_T c4_d_t;
  uint32_T c4_e_state;
  uint32_T c4_method2;
  uint32_T c4_r;
  uint32_T c4_u;
  uint32_T c4_u1;
  uint32_T c4_varargin_1;
  boolean_T c4_covSaturation;
  c4_st.tls = chartInstance->c4_fEmlrtCtx;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  chartInstance->c4_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 0U, *chartInstance->c4_t);
  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_b_t = *chartInstance->c4_t;
  covrtEmlFcnEval(chartInstance->c4_covrtInstance, 4U, 0, 0);
  if (covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 0,
                     covrtRelationalopUpdateFcn(chartInstance->c4_covrtInstance,
        4U, 0U, 0U, c4_mod(chartInstance, c4_b_t), 0.0, -1, 0U, c4_mod
        (chartInstance, c4_b_t) == 0.0))) {
    c4_b_st.site = &c4_emlrtRSI;
    if (!chartInstance->c4_seed_not_empty) {
      chartInstance->c4_seed = 0U;
      chartInstance->c4_seed_not_empty = true;
    }

    if (!chartInstance->c4_method_not_empty) {
      chartInstance->c4_method = 7U;
      chartInstance->c4_method_not_empty = true;
    }

    c4_x = c4_now(chartInstance) * 8.64E+6;
    c4_b_x = c4_x;
    c4_b_x = muDoubleScalarFloor(c4_b_x);
    c4_s = c4_b_mod(chartInstance, c4_b_x);
    c4_eTime = time(NULL);
    c4_prevEpochTime = (int32_T)c4_eTime + 1;
    do {
      c4_exitg1 = 0;
      c4_b_eTime = time(NULL);
      c4_c_t = (int32_T)c4_b_eTime;
      if (c4_c_t <= c4_prevEpochTime) {
        c4_e_x = c4_now(chartInstance) * 8.64E+6;
        c4_f_x = c4_e_x;
        c4_f_x = muDoubleScalarFloor(c4_f_x);
        c4_s0 = c4_b_mod(chartInstance, c4_f_x);
        if (c4_s != c4_s0) {
          c4_exitg1 = 1;
        }
      } else {
        c4_exitg1 = 1;
      }
    } while (c4_exitg1 == 0);

    c4_d = muDoubleScalarRound(c4_s);
    c4_covSaturation = false;
    if (c4_d < 4.294967296E+9) {
      if (c4_d >= 0.0) {
        c4_u = (uint32_T)c4_d;
      } else {
        c4_covSaturation = true;
        c4_u = 0U;
        sf_data_saturate_error(chartInstance->S, 1U, 78, 14);
      }
    } else if (c4_d >= 4.294967296E+9) {
      c4_covSaturation = true;
      c4_u = MAX_uint32_T;
      sf_data_saturate_error(chartInstance->S, 1U, 78, 14);
    } else {
      c4_u = 0U;
    }

    covrtSaturationUpdateFcn(chartInstance->c4_covrtInstance, 4, 0, 0, 0,
      c4_covSaturation);
    chartInstance->c4_seed = c4_u;
    if (!chartInstance->c4_method_not_empty) {
      chartInstance->c4_method = 7U;
      chartInstance->c4_method_not_empty = true;
    }

    c4_method2 = chartInstance->c4_method;
    if (c4_method2 == 7U) {
      c4_varargin_1 = chartInstance->c4_seed;
      if (!chartInstance->c4_state_not_empty) {
        for (c4_i13 = 0; c4_i13 < 625; c4_i13++) {
          chartInstance->c4_state[c4_i13] = c4_uv[c4_i13];
        }

        chartInstance->c4_state_not_empty = true;
      }

      c4_arg3 = c4_varargin_1;
      c4_b_seed = c4_arg3;
      c4_r = c4_b_seed;
      chartInstance->c4_state[0] = c4_b_seed;
      for (c4_mti = 0; c4_mti < 623; c4_mti++) {
        c4_b_mti = 2.0 + (real_T)c4_mti;
        c4_d1 = muDoubleScalarRound(c4_b_mti - 1.0);
        if (c4_d1 < 4.294967296E+9) {
          if (c4_d1 >= 0.0) {
            c4_u1 = (uint32_T)c4_d1;
          } else {
            c4_u1 = 0U;
            sf_data_saturate_error(chartInstance->S, 1U, 78, 14);
          }
        } else if (c4_d1 >= 4.294967296E+9) {
          c4_u1 = MAX_uint32_T;
          sf_data_saturate_error(chartInstance->S, 1U, 78, 14);
        } else {
          c4_u1 = 0U;
        }

        c4_r = (c4_r ^ c4_r >> 30U) * 1812433253U + c4_u1;
        chartInstance->c4_state[(int32_T)c4_b_mti - 1] = c4_r;
      }

      chartInstance->c4_state[624] = 624U;
    } else if (c4_method2 == 5U) {
      c4_b_varargin_1 = chartInstance->c4_seed;
      if (!chartInstance->c4_b_state_not_empty) {
        for (c4_i14 = 0; c4_i14 < 2; c4_i14++) {
          chartInstance->c4_b_state[c4_i14] = 362436069U + 158852560U *
            (uint32_T)c4_i14;
        }

        chartInstance->c4_b_state_not_empty = true;
      }

      c4_b_arg3 = c4_b_varargin_1;
      c4_b_s = c4_b_arg3;
      chartInstance->c4_b_state[0] = 362436069U;
      chartInstance->c4_b_state[1] = c4_b_s;
      if ((real_T)chartInstance->c4_b_state[1] == 0.0) {
        chartInstance->c4_b_state[1] = 521288629U;
      }
    } else if (c4_method2 == 4U) {
      c4_c_varargin_1 = chartInstance->c4_seed;
      if (!chartInstance->c4_c_state_not_empty) {
        chartInstance->c4_c_state = 1144108930U;
        chartInstance->c4_c_state_not_empty = true;
      }

      c4_c_arg3 = c4_c_varargin_1;
      c4_c_seed = c4_c_arg3;
      c4_b_r = c4_c_seed >> 16U;
      c4_d_t = c4_c_seed & 32768U;
      c4_e_state = c4_b_r << 16U;
      c4_e_state = c4_c_seed - c4_e_state;
      c4_e_state -= c4_d_t;
      c4_e_state <<= 16U;
      c4_e_state += c4_d_t;
      c4_e_state += c4_b_r;
      if ((real_T)c4_e_state < 1.0) {
        c4_e_state = 1144108930U;
      } else if (c4_e_state > 2147483646U) {
        c4_e_state = 2147483646U;
      }

      chartInstance->c4_c_state = c4_e_state;
    } else {
      c4_d_y = NULL;
      sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 22),
                    false);
      c4_e_y = NULL;
      sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 22),
                    false);
      sf_mex_call(&c4_b_st, &c4_emlrtMCI, "error", 0U, 2U, 14, c4_d_y, 14,
                  sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c4_b_st, NULL, "message", 1U, 1U, 14, c4_e_y)));
    }

    c4_b_st.site = &c4_b_emlrtRSI;
    c4_randn(chartInstance, &c4_b_st, c4_dv1);
    for (c4_i19 = 0; c4_i19 < 70; c4_i19++) {
      c4_set_a(chartInstance, c4_i19, c4_dv1[c4_i19]);
    }

    for (c4_i21 = 0; c4_i21 < 70; c4_i21++) {
      c4_set_a(chartInstance, c4_i21, c4_get_a(chartInstance, c4_i21) - 0.5);
    }

    ssUpdateDataStoreLog_wrapper(chartInstance->S, 0);
    c4_b_st.site = &c4_c_emlrtRSI;
    c4_randn(chartInstance, &c4_b_st, c4_dv2);
    for (c4_i22 = 0; c4_i22 < 70; c4_i22++) {
      c4_set_f(chartInstance, c4_i22, c4_dv2[c4_i22]);
    }

    for (c4_i23 = 0; c4_i23 < 70; c4_i23++) {
      c4_set_f(chartInstance, c4_i23, c4_get_f(chartInstance, c4_i23) *
               3.1415926535897931);
    }

    for (c4_i24 = 0; c4_i24 < 70; c4_i24++) {
      c4_set_f(chartInstance, c4_i24, c4_get_f(chartInstance, c4_i24) +
               0.62831853071795862);
    }

    ssUpdateDataStoreLog_wrapper(chartInstance->S, 2);
    c4_b_st.site = &c4_d_emlrtRSI;
    c4_randn(chartInstance, &c4_b_st, c4_dv3);
    for (c4_i25 = 0; c4_i25 < 70; c4_i25++) {
      c4_set_b(chartInstance, c4_i25, c4_dv3[c4_i25]);
    }

    for (c4_i26 = 0; c4_i26 < 70; c4_i26++) {
      c4_set_b(chartInstance, c4_i26, c4_get_b(chartInstance, c4_i26) * 2.0);
    }

    for (c4_i27 = 0; c4_i27 < 70; c4_i27++) {
      c4_set_b(chartInstance, c4_i27, c4_get_b(chartInstance, c4_i27) *
               3.1415926535897931);
    }

    ssUpdateDataStoreLog_wrapper(chartInstance->S, 1);
  }

  c4_b = c4_b_t;
  for (c4_i = 0; c4_i < 70; c4_i++) {
    c4_y[c4_i] = c4_get_f(chartInstance, c4_i) * c4_b;
  }

  for (c4_i1 = 0; c4_i1 < 70; c4_i1++) {
    c4_y[c4_i1] += c4_get_b(chartInstance, c4_i1);
  }

  for (c4_k = 0; c4_k < 70; c4_k++) {
    c4_b_k = c4_k;
    c4_c_x = c4_y[c4_b_k];
    c4_d_x = c4_c_x;
    c4_d_x = muDoubleScalarSin(c4_d_x);
    c4_y[c4_b_k] = c4_d_x;
  }

  for (c4_i2 = 0; c4_i2 < 70; c4_i2++) {
    c4_y[c4_i2] *= c4_get_a(chartInstance, c4_i2);
  }

  for (c4_col = 0; c4_col < 7; c4_col++) {
    c4_b_col = c4_col;
    for (c4_i4 = 0; c4_i4 < 70; c4_i4++) {
      c4_b_y[c4_i4] = c4_y[c4_i4];
    }

    (*chartInstance->c4_q)[c4_b_col] = c4_sumColumnB(chartInstance, c4_b_y,
      c4_b_col + 1);
  }

  for (c4_i3 = 0; c4_i3 < 7; c4_i3++) {
    (*chartInstance->c4_q)[c4_i3] = c4_B[c4_i3] * (*chartInstance->c4_q)[c4_i3] /
      5.0 + c4_dv[c4_i3];
  }

  c4_b_b = c4_b_t;
  for (c4_i5 = 0; c4_i5 < 70; c4_i5++) {
    c4_y[c4_i5] = c4_get_f(chartInstance, c4_i5) * c4_b_b;
  }

  for (c4_i6 = 0; c4_i6 < 70; c4_i6++) {
    c4_y[c4_i6] += c4_get_b(chartInstance, c4_i6);
  }

  for (c4_c_k = 0; c4_c_k < 70; c4_c_k++) {
    c4_d_k = c4_c_k;
    c4_g_x = c4_y[c4_d_k];
    c4_h_x = c4_g_x;
    c4_h_x = muDoubleScalarCos(c4_h_x);
    c4_y[c4_d_k] = c4_h_x;
  }

  for (c4_i7 = 0; c4_i7 < 70; c4_i7++) {
    c4_y[c4_i7] *= c4_get_a(chartInstance, c4_i7) * c4_get_f(chartInstance,
      c4_i7);
  }

  for (c4_c_col = 0; c4_c_col < 7; c4_c_col++) {
    c4_d_col = c4_c_col;
    for (c4_i9 = 0; c4_i9 < 70; c4_i9++) {
      c4_c_y[c4_i9] = c4_y[c4_i9];
    }

    (*chartInstance->c4_qd)[c4_d_col] = c4_sumColumnB(chartInstance, c4_c_y,
      c4_d_col + 1);
  }

  for (c4_i8 = 0; c4_i8 < 7; c4_i8++) {
    (*chartInstance->c4_qd)[c4_i8] = c4_B[c4_i8] * (*chartInstance->c4_qd)[c4_i8]
      / 5.0;
  }

  c4_c_b = c4_b_t;
  for (c4_i10 = 0; c4_i10 < 70; c4_i10++) {
    c4_y[c4_i10] = c4_get_f(chartInstance, c4_i10) * c4_c_b;
  }

  for (c4_i11 = 0; c4_i11 < 70; c4_i11++) {
    c4_y[c4_i11] += c4_get_b(chartInstance, c4_i11);
  }

  for (c4_e_k = 0; c4_e_k < 70; c4_e_k++) {
    c4_f_k = c4_e_k;
    c4_i_x = c4_y[c4_f_k];
    c4_j_x = c4_i_x;
    c4_j_x = muDoubleScalarSin(c4_j_x);
    c4_y[c4_f_k] = c4_j_x;
  }

  for (c4_i12 = 0; c4_i12 < 70; c4_i12++) {
    c4_y[c4_i12] *= -c4_get_a(chartInstance, c4_i12) * c4_get_f(chartInstance,
      c4_i12) * c4_get_f(chartInstance, c4_i12);
  }

  for (c4_e_col = 0; c4_e_col < 7; c4_e_col++) {
    c4_f_col = c4_e_col;
    for (c4_i16 = 0; c4_i16 < 70; c4_i16++) {
      c4_f_y[c4_i16] = c4_y[c4_i16];
    }

    (*chartInstance->c4_qdd)[c4_f_col] = c4_sumColumnB(chartInstance, c4_f_y,
      c4_f_col + 1);
  }

  for (c4_i15 = 0; c4_i15 < 7; c4_i15++) {
    (*chartInstance->c4_qdd)[c4_i15] = c4_B[c4_i15] * (*chartInstance->c4_qdd)
      [c4_i15] / 5.0;
  }

  c4_do_animation_call_c4_data(chartInstance);
  for (c4_i17 = 0; c4_i17 < 7; c4_i17++) {
    covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 1U, (*chartInstance->c4_q)
                      [c4_i17]);
  }

  for (c4_i18 = 0; c4_i18 < 7; c4_i18++) {
    covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 2U,
                      (*chartInstance->c4_qd)[c4_i18]);
  }

  for (c4_i20 = 0; c4_i20 < 7; c4_i20++) {
    covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 3U,
                      (*chartInstance->c4_qdd)[c4_i20]);
  }
}

static void mdl_start_c4_data(SFc4_dataInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c4_data(SFc4_dataInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c4_data(SFc4_dataInstanceStruct
  *chartInstance)
{
  static const uint32_T c4_decisionTxtEndIdx = 0U;
  static const uint32_T c4_decisionTxtStartIdx = 0U;
  setLegacyDebuggerFlag(chartInstance->S, false);
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c4_chart_data_browse_helper);
  chartInstance->c4_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c4_RuntimeVar,
    &chartInstance->c4_IsDebuggerActive,
    &chartInstance->c4_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c4_mlFcnLineNumber, &chartInstance->c4_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c4_covrtInstance, 1U, 0U, 1U,
    14U);
  covrtChartInitFcn(chartInstance->c4_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c4_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c4_decisionTxtStartIdx, &c4_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c4_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c4_covrtInstance, "", 4U, 0U, 1U, 0U, 1U, 0U,
                  1U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 533);
  covrtEmlSaturationInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 78, -1,
    92);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 57, 72, -1, 175);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 60, 72,
    -1, 0U);
}

static void mdl_cleanup_runtime_resources_c4_data(SFc4_dataInstanceStruct
  *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c4_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c4_covrtInstance);
}

static void initSimStructsc4_data(SFc4_dataInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c4_data_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static real_T c4_mod(SFc4_dataInstanceStruct *chartInstance, real_T c4_x)
{
  real_T c4_a;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_r;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_rEQ0;
  (void)chartInstance;
  c4_a = c4_x;
  c4_b_x = c4_a;
  c4_c_x = c4_b_x;
  c4_d_x = c4_c_x;
  c4_b = muDoubleScalarIsNaN(c4_d_x);
  if (c4_b) {
    c4_r = rtNaN;
  } else {
    c4_e_x = c4_c_x;
    c4_b_b = muDoubleScalarIsInf(c4_e_x);
    if (c4_b_b) {
      c4_r = rtNaN;
    } else if (c4_c_x == 0.0) {
      c4_r = 0.0;
    } else {
      c4_r = muDoubleScalarRem(c4_c_x, 10.0);
      c4_rEQ0 = (c4_r == 0.0);
      if (c4_rEQ0) {
        c4_r = 0.0;
      } else if (c4_c_x < 0.0) {
        c4_r += 10.0;
      }
    }
  }

  return c4_r;
}

static real_T c4_now(SFc4_dataInstanceStruct *chartInstance)
{
  time_t c4_rawtime;
  c4_sxaDueAh1f53T9ESYg9Uc4E c4_timeinfoDouble;
  struct tm c4_timeinfo;
  real_T c4_cDaysMonthWise[12];
  real_T c4_a;
  real_T c4_b_a;
  real_T c4_b_r;
  real_T c4_b_x;
  real_T c4_c_a;
  real_T c4_c_r;
  real_T c4_c_x;
  real_T c4_dDateNum;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_i_x;
  real_T c4_j_x;
  real_T c4_k_x;
  real_T c4_l_x;
  real_T c4_m_x;
  real_T c4_n_x;
  real_T c4_o_x;
  real_T c4_p_x;
  real_T c4_q_x;
  real_T c4_r;
  real_T c4_r_x;
  real_T c4_s_x;
  real_T c4_t_x;
  real_T c4_u_x;
  real_T c4_x;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_b_rEQ0;
  boolean_T c4_c_b;
  boolean_T c4_c_rEQ0;
  boolean_T c4_d_b;
  boolean_T c4_e_b;
  boolean_T c4_f_b;
  boolean_T c4_guard1 = false;
  boolean_T c4_rEQ0;
  (void)chartInstance;
  c4_cDaysMonthWise[0] = 0.0;
  c4_cDaysMonthWise[1] = 31.0;
  c4_cDaysMonthWise[2] = 59.0;
  c4_cDaysMonthWise[3] = 90.0;
  c4_cDaysMonthWise[4] = 120.0;
  c4_cDaysMonthWise[5] = 151.0;
  c4_cDaysMonthWise[6] = 181.0;
  c4_cDaysMonthWise[7] = 212.0;
  c4_cDaysMonthWise[8] = 243.0;
  c4_cDaysMonthWise[9] = 273.0;
  c4_cDaysMonthWise[10] = 304.0;
  c4_cDaysMonthWise[11] = 334.0;
  time(&c4_rawtime);
  c4_timeinfo = *localtime(&c4_rawtime);
  c4_timeinfo.tm_year += 1900;
  c4_timeinfo.tm_mon++;
  c4_timeinfoDouble.tm_min = (real_T)c4_timeinfo.tm_min;
  c4_timeinfoDouble.tm_sec = (real_T)c4_timeinfo.tm_sec;
  c4_timeinfoDouble.tm_hour = (real_T)c4_timeinfo.tm_hour;
  c4_timeinfoDouble.tm_mday = (real_T)c4_timeinfo.tm_mday;
  c4_timeinfoDouble.tm_mon = (real_T)c4_timeinfo.tm_mon;
  c4_timeinfoDouble.tm_year = (real_T)c4_timeinfo.tm_year;
  c4_x = c4_timeinfoDouble.tm_year / 4.0;
  c4_b_x = c4_x;
  c4_b_x = muDoubleScalarCeil(c4_b_x);
  c4_c_x = c4_timeinfoDouble.tm_year / 100.0;
  c4_d_x = c4_c_x;
  c4_d_x = muDoubleScalarCeil(c4_d_x);
  c4_e_x = c4_timeinfoDouble.tm_year / 400.0;
  c4_f_x = c4_e_x;
  c4_f_x = muDoubleScalarCeil(c4_f_x);
  c4_dDateNum = ((((365.0 * c4_timeinfoDouble.tm_year + c4_b_x) - c4_d_x) +
                  c4_f_x) + c4_cDaysMonthWise[(int32_T)c4_timeinfoDouble.tm_mon
                 - 1]) + c4_timeinfoDouble.tm_mday;
  if (c4_timeinfoDouble.tm_mon > 2.0) {
    c4_g_x = c4_timeinfoDouble.tm_year;
    c4_a = c4_g_x;
    c4_h_x = c4_a;
    c4_i_x = c4_h_x;
    c4_j_x = c4_i_x;
    c4_b = muDoubleScalarIsNaN(c4_j_x);
    if (c4_b) {
      c4_r = rtNaN;
    } else {
      c4_k_x = c4_i_x;
      c4_b_b = muDoubleScalarIsInf(c4_k_x);
      if (c4_b_b) {
        c4_r = rtNaN;
      } else if (c4_i_x == 0.0) {
        c4_r = 0.0;
      } else {
        c4_r = muDoubleScalarRem(c4_i_x, 4.0);
        c4_rEQ0 = (c4_r == 0.0);
        if (c4_rEQ0) {
          c4_r = 0.0;
        } else if (c4_i_x < 0.0) {
          c4_r += 4.0;
        }
      }
    }

    c4_guard1 = false;
    if (c4_r == 0.0) {
      c4_l_x = c4_timeinfoDouble.tm_year;
      c4_b_a = c4_l_x;
      c4_m_x = c4_b_a;
      c4_o_x = c4_m_x;
      c4_p_x = c4_o_x;
      c4_c_b = muDoubleScalarIsNaN(c4_p_x);
      if (c4_c_b) {
        c4_b_r = rtNaN;
      } else {
        c4_t_x = c4_o_x;
        c4_e_b = muDoubleScalarIsInf(c4_t_x);
        if (c4_e_b) {
          c4_b_r = rtNaN;
        } else if (c4_o_x == 0.0) {
          c4_b_r = 0.0;
        } else {
          c4_b_r = muDoubleScalarRem(c4_o_x, 100.0);
          c4_b_rEQ0 = (c4_b_r == 0.0);
          if (c4_b_rEQ0) {
            c4_b_r = 0.0;
          } else if (c4_o_x < 0.0) {
            c4_b_r += 100.0;
          }
        }
      }

      if (c4_b_r != 0.0) {
        c4_dDateNum++;
      } else {
        c4_guard1 = true;
      }
    } else {
      c4_guard1 = true;
    }

    if (c4_guard1) {
      c4_n_x = c4_timeinfoDouble.tm_year;
      c4_c_a = c4_n_x;
      c4_q_x = c4_c_a;
      c4_r_x = c4_q_x;
      c4_s_x = c4_r_x;
      c4_d_b = muDoubleScalarIsNaN(c4_s_x);
      if (c4_d_b) {
        c4_c_r = rtNaN;
      } else {
        c4_u_x = c4_r_x;
        c4_f_b = muDoubleScalarIsInf(c4_u_x);
        if (c4_f_b) {
          c4_c_r = rtNaN;
        } else if (c4_r_x == 0.0) {
          c4_c_r = 0.0;
        } else {
          c4_c_r = muDoubleScalarRem(c4_r_x, 400.0);
          c4_c_rEQ0 = (c4_c_r == 0.0);
          if (c4_c_rEQ0) {
            c4_c_r = 0.0;
          } else if (c4_r_x < 0.0) {
            c4_c_r += 400.0;
          }
        }
      }

      if (c4_c_r == 0.0) {
        c4_dDateNum++;
      }
    }
  }

  c4_dDateNum += ((c4_timeinfoDouble.tm_hour * 3600.0 + c4_timeinfoDouble.tm_min
                   * 60.0) + c4_timeinfoDouble.tm_sec) / 86400.0;
  return c4_dDateNum;
}

static real_T c4_b_mod(SFc4_dataInstanceStruct *chartInstance, real_T c4_x)
{
  real_T c4_a;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_r;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_rEQ0;
  (void)chartInstance;
  c4_a = c4_x;
  c4_b_x = c4_a;
  c4_c_x = c4_b_x;
  c4_d_x = c4_c_x;
  c4_b = muDoubleScalarIsNaN(c4_d_x);
  if (c4_b) {
    c4_r = rtNaN;
  } else {
    c4_e_x = c4_c_x;
    c4_b_b = muDoubleScalarIsInf(c4_e_x);
    if (c4_b_b) {
      c4_r = rtNaN;
    } else if (c4_c_x == 0.0) {
      c4_r = 0.0;
    } else {
      c4_r = muDoubleScalarRem(c4_c_x, 2.147483647E+9);
      c4_rEQ0 = (c4_r == 0.0);
      if (c4_rEQ0) {
        c4_r = 0.0;
      } else if (c4_c_x < 0.0) {
        c4_r += 2.147483647E+9;
      }
    }
  }

  return c4_r;
}

static void c4_randn(SFc4_dataInstanceStruct *chartInstance, const emlrtStack
                     *c4_sp, real_T c4_r[70])
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_st;
  real_T c4_b_r;
  real_T c4_b_t;
  real_T c4_c_k;
  real_T c4_c_r;
  real_T c4_c_t;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d2;
  real_T c4_d3;
  real_T c4_d4;
  real_T c4_d_r;
  real_T c4_d_t;
  real_T c4_e_r;
  real_T c4_e_t;
  real_T c4_g_k;
  real_T c4_h_k;
  real_T c4_i_k;
  int32_T c4_b_k;
  int32_T c4_d_k;
  int32_T c4_e_k;
  int32_T c4_f_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_k;
  uint32_T c4_e_state;
  uint32_T c4_f_state;
  uint32_T c4_g_state;
  uint32_T c4_h_state;
  uint32_T c4_i_state;
  uint32_T c4_j_state;
  uint32_T c4_k_state;
  uint32_T c4_l_state;
  uint32_T c4_m_state;
  uint32_T c4_n_state;
  uint32_T c4_o_state;
  uint32_T c4_u;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_s_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  if (!chartInstance->c4_b_method_not_empty) {
    chartInstance->c4_b_method = 0U;
    chartInstance->c4_b_method_not_empty = true;
    for (c4_i = 0; c4_i < 2; c4_i++) {
      chartInstance->c4_d_state[c4_i] = 362436069U + 158852560U * (uint32_T)c4_i;
    }

    chartInstance->c4_d_state_not_empty = true;
  }

  if (chartInstance->c4_b_method == 0U) {
    c4_b_st.site = &c4_t_emlrtRSI;
    if (!chartInstance->c4_method_not_empty) {
      chartInstance->c4_method = 7U;
      chartInstance->c4_method_not_empty = true;
    }

    if (chartInstance->c4_method == 4U) {
      c4_c_st.site = &c4_v_emlrtRSI;
      if (!chartInstance->c4_c_state_not_empty) {
        chartInstance->c4_c_state = 1144108930U;
        chartInstance->c4_c_state_not_empty = true;
      }

      for (c4_d_k = 0; c4_d_k < 70; c4_d_k++) {
        c4_g_k = 1.0 + (real_T)c4_d_k;
        c4_j_state = chartInstance->c4_c_state;
        c4_k_state = c4_j_state;
        c4_l_state = c4_k_state;
        c4_m_state = c4_l_state;
        do {
          c4_genrandu(chartInstance, c4_m_state, &c4_n_state, &c4_d_r);
          c4_genrandu(chartInstance, c4_n_state, &c4_o_state, &c4_d_t);
          c4_m_state = c4_o_state;
          c4_e_r = 2.0 * c4_d_r - 1.0;
          c4_e_t = 2.0 * c4_d_t - 1.0;
          c4_e_t = c4_e_t * c4_e_t + c4_e_r * c4_e_r;
        } while (!(c4_e_t <= 1.0));

        c4_e_r *= muDoubleScalarSqrt(-2.0 * muDoubleScalarLog(c4_e_t) / c4_e_t);
        c4_k_state = c4_m_state;
        c4_d4 = c4_e_r;
        chartInstance->c4_c_state = c4_k_state;
        c4_r[(int32_T)c4_g_k - 1] = c4_d4;
      }
    } else if (chartInstance->c4_method == 5U) {
      c4_c_st.site = &c4_w_emlrtRSI;
      if (!chartInstance->c4_b_state_not_empty) {
        for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
          chartInstance->c4_b_state[c4_i2] = 362436069U + 158852560U * (uint32_T)
            c4_i2;
        }

        chartInstance->c4_b_state_not_empty = true;
      }

      for (c4_f_k = 0; c4_f_k < 70; c4_f_k++) {
        c4_i_k = 1.0 + (real_T)c4_f_k;
        c4_d1 = c4_b_eml_rand_shr3cong(chartInstance, chartInstance->c4_b_state);
        c4_r[(int32_T)c4_i_k - 1] = c4_d1;
      }
    } else {
      c4_c_st.site = &c4_x_emlrtRSI;
      if (!chartInstance->c4_state_not_empty) {
        for (c4_i1 = 0; c4_i1 < 625; c4_i1++) {
          chartInstance->c4_state[c4_i1] = c4_uv[c4_i1];
        }

        chartInstance->c4_state_not_empty = true;
      }

      for (c4_e_k = 0; c4_e_k < 70; c4_e_k++) {
        c4_h_k = 1.0 + (real_T)c4_e_k;
        c4_d_st.site = &c4_fb_emlrtRSI;
        c4_d2 = c4_b_eml_rand_mt19937ar(chartInstance, &c4_d_st,
          chartInstance->c4_state);
        c4_r[(int32_T)c4_h_k - 1] = c4_d2;
      }
    }
  } else if (chartInstance->c4_b_method == 4U) {
    for (c4_b_k = 0; c4_b_k < 70; c4_b_k++) {
      c4_c_k = 1.0 + (real_T)c4_b_k;
      c4_e_state = chartInstance->c4_d_state[0];
      c4_u = c4_e_state;
      c4_f_state = c4_u;
      c4_g_state = c4_f_state;
      do {
        c4_genrandu(chartInstance, c4_g_state, &c4_h_state, &c4_b_r);
        c4_genrandu(chartInstance, c4_h_state, &c4_i_state, &c4_b_t);
        c4_g_state = c4_i_state;
        c4_c_r = 2.0 * c4_b_r - 1.0;
        c4_c_t = 2.0 * c4_b_t - 1.0;
        c4_c_t = c4_c_t * c4_c_t + c4_c_r * c4_c_r;
      } while (!(c4_c_t <= 1.0));

      c4_c_r *= muDoubleScalarSqrt(-2.0 * muDoubleScalarLog(c4_c_t) / c4_c_t);
      c4_u = c4_g_state;
      c4_d3 = c4_c_r;
      chartInstance->c4_d_state[0] = c4_u;
      c4_r[(int32_T)c4_c_k - 1] = c4_d3;
    }
  } else {
    for (c4_k = 0; c4_k < 70; c4_k++) {
      c4_c_k = 1.0 + (real_T)c4_k;
      c4_b_st.site = &c4_u_emlrtRSI;
      c4_d = c4_b_eml_rand_shr3cong(chartInstance, chartInstance->c4_d_state);
      c4_r[(int32_T)c4_c_k - 1] = c4_d;
    }
  }
}

static void c4_genrandu(SFc4_dataInstanceStruct *chartInstance, uint32_T c4_s,
  uint32_T *c4_e_state, real_T *c4_r)
{
  uint32_T c4_a;
  uint32_T c4_b;
  uint32_T c4_hi;
  uint32_T c4_lo;
  uint32_T c4_test1;
  uint32_T c4_test2;
  (void)chartInstance;
  c4_hi = c4_s / 127773U;
  c4_lo = c4_s - c4_hi * 127773U;
  c4_test1 = 16807U * c4_lo;
  c4_test2 = 2836U * c4_hi;
  c4_a = c4_test1;
  c4_b = c4_test2;
  if (c4_a < c4_b) {
    *c4_e_state = c4_b - c4_a;
    *c4_e_state = ~*c4_e_state;
    *c4_e_state &= 2147483647U;
  } else {
    *c4_e_state = c4_a - c4_b;
  }

  *c4_r = (real_T)*c4_e_state * 4.6566128752457969E-10;
}

static void c4_eml_rand_shr3cong(SFc4_dataInstanceStruct *chartInstance,
  uint32_T c4_e_state[2], uint32_T c4_f_state[2], real_T *c4_r)
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 2; c4_i++) {
    c4_f_state[c4_i] = c4_e_state[c4_i];
  }

  *c4_r = c4_b_eml_rand_shr3cong(chartInstance, c4_f_state);
}

static void c4_eml_rand_mt19937ar(SFc4_dataInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, uint32_T c4_e_state[625], uint32_T c4_f_state[625], real_T *
  c4_r)
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 625; c4_i++) {
    c4_f_state[c4_i] = c4_e_state[c4_i];
  }

  *c4_r = c4_b_eml_rand_mt19937ar(chartInstance, c4_sp, c4_f_state);
}

static void c4_genrand_uint32_vector(SFc4_dataInstanceStruct *chartInstance,
  uint32_T c4_mt[625], uint32_T c4_b_mt[625], uint32_T c4_u[2])
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 625; c4_i++) {
    c4_b_mt[c4_i] = c4_mt[c4_i];
  }

  c4_b_genrand_uint32_vector(chartInstance, c4_b_mt, c4_u);
}

static void c4_b_genrandu(SFc4_dataInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, uint32_T c4_mt[625], uint32_T c4_b_mt[625], real_T *c4_r)
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 625; c4_i++) {
    c4_b_mt[c4_i] = c4_mt[c4_i];
  }

  *c4_r = c4_c_genrandu(chartInstance, c4_sp, c4_b_mt);
}

static real_T c4_sumColumnB(SFc4_dataInstanceStruct *chartInstance, real_T c4_x
  [70], int32_T c4_col)
{
  real_T c4_y;
  int32_T c4_b_col;
  int32_T c4_b_k;
  int32_T c4_i0;
  int32_T c4_k;
  (void)chartInstance;
  c4_b_col = c4_col - 1;
  c4_i0 = c4_b_col * 10;
  c4_y = c4_x[c4_i0];
  for (c4_k = 0; c4_k < 9; c4_k++) {
    c4_b_k = c4_k;
    c4_y += c4_x[(c4_i0 + c4_b_k) + 1];
  }

  return c4_y;
}

static void c4_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance, const
  mxArray *c4_b_q, const char_T *c4_identifier, real_T c4_y[7])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_q), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_q);
}

static void c4_b_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance, const
  mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[7])
{
  real_T c4_dv[7];
  int32_T c4_i;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv, 1, 0, 0U, 1, 0U, 1, 7);
  for (c4_i = 0; c4_i < 7; c4_i++) {
    c4_y[c4_i] = c4_dv[c4_i];
  }

  sf_mex_destroy(&c4_u);
}

static uint32_T c4_c_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance,
  const mxArray *c4_c_method, const char_T *c4_identifier, boolean_T *c4_svPtr)
{
  emlrtMsgIdentifier c4_thisId;
  uint32_T c4_y;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_c_method),
    &c4_thisId, c4_svPtr);
  sf_mex_destroy(&c4_c_method);
  return c4_y;
}

static uint32_T c4_d_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, boolean_T
  *c4_svPtr)
{
  uint32_T c4_b_u;
  uint32_T c4_y;
  (void)chartInstance;
  if (mxIsEmpty(c4_u)) {
    *c4_svPtr = false;
  } else {
    *c4_svPtr = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_b_u, 1, 7, 0U, 0, 0U, 0);
    c4_y = c4_b_u;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_e_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance, const
  mxArray *c4_e_state, const char_T *c4_identifier, boolean_T *c4_svPtr,
  uint32_T c4_y[625])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_e_state), &c4_thisId,
                        c4_svPtr, c4_y);
  sf_mex_destroy(&c4_e_state);
}

static void c4_f_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance, const
  mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, boolean_T *c4_svPtr,
  uint32_T c4_y[625])
{
  int32_T c4_i;
  uint32_T c4_b_uv[625];
  (void)chartInstance;
  if (mxIsEmpty(c4_u)) {
    *c4_svPtr = false;
  } else {
    *c4_svPtr = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_b_uv, 1, 7, 0U, 1, 0U, 1,
                  625);
    for (c4_i = 0; c4_i < 625; c4_i++) {
      c4_y[c4_i] = c4_b_uv[c4_i];
    }
  }

  sf_mex_destroy(&c4_u);
}

static void c4_g_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance, const
  mxArray *c4_e_state, const char_T *c4_identifier, boolean_T *c4_svPtr,
  uint32_T c4_y[2])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_e_state), &c4_thisId,
                        c4_svPtr, c4_y);
  sf_mex_destroy(&c4_e_state);
}

static void c4_h_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance, const
  mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, boolean_T *c4_svPtr,
  uint32_T c4_y[2])
{
  int32_T c4_i;
  uint32_T c4_b_uv[2];
  (void)chartInstance;
  if (mxIsEmpty(c4_u)) {
    *c4_svPtr = false;
  } else {
    *c4_svPtr = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_b_uv, 1, 7, 0U, 1, 0U, 1, 2);
    for (c4_i = 0; c4_i < 2; c4_i++) {
      c4_y[c4_i] = c4_b_uv[c4_i];
    }
  }

  sf_mex_destroy(&c4_u);
}

static uint8_T c4_i_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_data, const char_T *c4_identifier)
{
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_is_active_c4_data),
    &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_data);
  return c4_y;
}

static uint8_T c4_j_emlrt_marshallIn(SFc4_dataInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_b_u;
  uint8_T c4_y;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_b_u, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_b_u;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_chart_data_browse_helper(SFc4_dataInstanceStruct *chartInstance,
  int32_T c4_ssIdNumber, const mxArray **c4_mxData, uint8_T *c4_isValueTooBig)
{
  real_T c4_d;
  *c4_mxData = NULL;
  *c4_mxData = NULL;
  *c4_isValueTooBig = 0U;
  switch (c4_ssIdNumber) {
   case 4U:
    c4_d = *chartInstance->c4_t;
    sf_mex_assign(c4_mxData, sf_mex_create("mxData", &c4_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 5U:
    sf_mex_assign(c4_mxData, sf_mex_create("mxData", *chartInstance->c4_q, 0, 0U,
      1U, 0U, 1, 7), false);
    break;

   case 6U:
    sf_mex_assign(c4_mxData, sf_mex_create("mxData", *chartInstance->c4_qd, 0,
      0U, 1U, 0U, 1, 7), false);
    break;

   case 7U:
    sf_mex_assign(c4_mxData, sf_mex_create("mxData", *chartInstance->c4_qdd, 0,
      0U, 1U, 0U, 1, 7), false);
    break;

   case 10U:
    sf_mex_assign(c4_mxData, sf_mex_create("mxData", c4_access_a(chartInstance,
      true), 0, 0U, 1U, 0U, 2, 10, 7), false);
    break;

   case 11U:
    sf_mex_assign(c4_mxData, sf_mex_create("mxData", c4_access_f(chartInstance,
      true), 0, 0U, 1U, 0U, 2, 10, 7), false);
    break;

   case 12U:
    sf_mex_assign(c4_mxData, sf_mex_create("mxData", c4_access_b(chartInstance,
      true), 0, 0U, 1U, 0U, 2, 10, 7), false);
    break;
  }
}

static real_T c4_b_eml_rand_shr3cong(SFc4_dataInstanceStruct *chartInstance,
  uint32_T c4_e_state[2])
{
  static real_T c4_dv[65] = { 0.340945, 0.4573146, 0.5397793, 0.6062427,
    0.6631691, 0.7136975, 0.7596125, 0.8020356, 0.8417227, 0.8792102, 0.9148948,
    0.9490791, 0.9820005, 1.0138492, 1.044781, 1.0749254, 1.1043917, 1.1332738,
    1.161653, 1.189601, 1.2171815, 1.2444516, 1.2714635, 1.298265, 1.3249008,
    1.3514125, 1.3778399, 1.4042211, 1.4305929, 1.4569915, 1.4834527, 1.5100122,
    1.5367061, 1.5635712, 1.5906454, 1.617968, 1.6455802, 1.6735255, 1.7018503,
    1.7306045, 1.7598422, 1.7896223, 1.8200099, 1.851077, 1.8829044, 1.9155831,
    1.9492166, 1.9839239, 2.0198431, 2.0571356, 2.095993, 2.136645, 2.1793713,
    2.2245175, 2.2725186, 2.3239338, 2.3795008, 2.4402218, 2.5075117, 2.5834658,
    2.6713916, 2.7769942, 2.7769942, 2.7769942, 2.7769942 };

  real_T c4_b_r;
  real_T c4_b_x;
  real_T c4_b_y;
  real_T c4_c_r;
  real_T c4_c_x;
  real_T c4_c_y;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_i_x;
  real_T c4_s;
  real_T c4_x;
  real_T c4_y;
  int32_T c4_i;
  uint32_T c4_b_icng;
  uint32_T c4_b_jsr;
  uint32_T c4_b_ui;
  uint32_T c4_c_icng;
  uint32_T c4_c_jsr;
  uint32_T c4_c_ui;
  uint32_T c4_d_icng;
  uint32_T c4_d_jsr;
  uint32_T c4_d_ui;
  uint32_T c4_e_icng;
  uint32_T c4_e_jsr;
  uint32_T c4_f_icng;
  uint32_T c4_f_jsr;
  uint32_T c4_g_icng;
  uint32_T c4_g_jsr;
  uint32_T c4_h_icng;
  uint32_T c4_h_jsr;
  uint32_T c4_i_icng;
  uint32_T c4_i_jsr;
  uint32_T c4_icng;
  uint32_T c4_j;
  uint32_T c4_jp1;
  uint32_T c4_jsr;
  uint32_T c4_ui;
  (void)chartInstance;
  c4_icng = c4_e_state[0];
  c4_jsr = c4_e_state[1];
  c4_b_icng = c4_icng;
  c4_b_jsr = c4_jsr;
  c4_c_jsr = c4_b_jsr;
  c4_c_icng = c4_b_icng;
  c4_c_icng = 69069U * c4_c_icng + 1234567U;
  c4_c_jsr ^= c4_c_jsr << 13;
  c4_c_jsr ^= c4_c_jsr >> 17;
  c4_c_jsr ^= c4_c_jsr << 5;
  c4_ui = c4_c_icng + c4_c_jsr;
  c4_icng = c4_c_icng;
  c4_jsr = c4_c_jsr;
  c4_j = (c4_ui & 63U) + 1U;
  c4_jp1 = c4_j + 1U;
  c4_i = (int32_T)c4_ui;
  c4_b_r = (real_T)c4_i * 4.6566128730773926E-10 * c4_dv[(int32_T)c4_jp1 - 1];
  c4_x = c4_b_r;
  c4_b_x = c4_x;
  c4_c_x = c4_b_x;
  c4_y = muDoubleScalarAbs(c4_c_x);
  if (c4_y <= c4_dv[(int32_T)c4_j - 1]) {
    c4_c_r = c4_b_r;
  } else {
    c4_d_x = c4_b_r;
    c4_e_x = c4_d_x;
    c4_f_x = c4_e_x;
    c4_b_y = muDoubleScalarAbs(c4_f_x);
    c4_g_x = (c4_b_y - c4_dv[(int32_T)c4_j - 1]) / (c4_dv[(int32_T)c4_jp1 - 1] -
      c4_dv[(int32_T)c4_j - 1]);
    c4_d_icng = c4_c_icng;
    c4_d_jsr = c4_c_jsr;
    c4_e_jsr = c4_d_jsr;
    c4_e_icng = c4_d_icng;
    c4_e_icng = 69069U * c4_e_icng + 1234567U;
    c4_e_jsr ^= c4_e_jsr << 13;
    c4_e_jsr ^= c4_e_jsr >> 17;
    c4_e_jsr ^= c4_e_jsr << 5;
    c4_b_ui = c4_e_icng + c4_e_jsr;
    c4_icng = c4_e_icng;
    c4_jsr = c4_e_jsr;
    c4_i = (int32_T)c4_b_ui;
    c4_c_y = 0.5 + (real_T)c4_i * 2.328306436538696E-10;
    c4_s = c4_g_x + c4_c_y;
    if (c4_s > 1.301198) {
      if (c4_b_r < 0.0) {
        c4_c_r = 0.4878992 * c4_g_x - 0.4878992;
      } else {
        c4_c_r = 0.4878992 - 0.4878992 * c4_g_x;
      }
    } else if (c4_s <= 0.9689279) {
      c4_c_r = c4_b_r;
    } else {
      c4_g_x = 0.4878992 - 0.4878992 * c4_g_x;
      if (c4_c_y > 12.67706 - 12.37586 * muDoubleScalarExp(-0.5 * c4_g_x *
           c4_g_x)) {
        if (c4_b_r < 0.0) {
          c4_c_r = -c4_g_x;
        } else {
          c4_c_r = c4_g_x;
        }
      } else {
        c4_h_x = -0.5 * c4_dv[(int32_T)c4_jp1 - 1] * c4_dv[(int32_T)c4_jp1 - 1];
        c4_i_x = c4_h_x;
        c4_i_x = muDoubleScalarExp(c4_i_x);
        if (c4_i_x + c4_c_y * 0.01958303 / c4_dv[(int32_T)c4_jp1 - 1] <=
            muDoubleScalarExp(-0.5 * c4_b_r * c4_b_r)) {
          c4_c_r = c4_b_r;
        } else {
          do {
            c4_f_icng = c4_icng;
            c4_f_jsr = c4_jsr;
            c4_g_jsr = c4_f_jsr;
            c4_g_icng = c4_f_icng;
            c4_g_icng = 69069U * c4_g_icng + 1234567U;
            c4_g_jsr ^= c4_g_jsr << 13;
            c4_g_jsr ^= c4_g_jsr >> 17;
            c4_g_jsr ^= c4_g_jsr << 5;
            c4_c_ui = c4_g_icng + c4_g_jsr;
            c4_i = (int32_T)c4_c_ui;
            c4_g_x = muDoubleScalarLog(0.5 + (real_T)c4_i *
              2.328306436538696E-10) / 2.776994;
            c4_h_icng = c4_g_icng;
            c4_h_jsr = c4_g_jsr;
            c4_i_jsr = c4_h_jsr;
            c4_i_icng = c4_h_icng;
            c4_i_icng = 69069U * c4_i_icng + 1234567U;
            c4_i_jsr ^= c4_i_jsr << 13;
            c4_i_jsr ^= c4_i_jsr >> 17;
            c4_i_jsr ^= c4_i_jsr << 5;
            c4_d_ui = c4_i_icng + c4_i_jsr;
            c4_icng = c4_i_icng;
            c4_jsr = c4_i_jsr;
            c4_i = (int32_T)c4_d_ui;
          } while (!(-2.0 * muDoubleScalarLog(0.5 + (real_T)c4_i *
                     2.328306436538696E-10) > c4_g_x * c4_g_x));

          if (c4_b_r < 0.0) {
            c4_c_r = c4_g_x - 2.776994;
          } else {
            c4_c_r = 2.776994 - c4_g_x;
          }
        }
      }
    }
  }

  c4_e_state[0] = c4_icng;
  c4_e_state[1] = c4_jsr;
  return c4_c_r;
}

static real_T c4_b_eml_rand_mt19937ar(SFc4_dataInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, uint32_T c4_e_state[625])
{
  static real_T c4_dv[257] = { 0.0, 0.215241895984875, 0.286174591792068,
    0.335737519214422, 0.375121332878378, 0.408389134611989, 0.43751840220787,
    0.46363433679088, 0.487443966139235, 0.50942332960209, 0.529909720661557,
    0.549151702327164, 0.567338257053817, 0.584616766106378, 0.601104617755991,
    0.61689699000775, 0.63207223638606, 0.646695714894993, 0.660822574244419,
    0.674499822837293, 0.687767892795788, 0.700661841106814, 0.713212285190975,
    0.725446140909999, 0.737387211434295, 0.749056662017815, 0.760473406430107,
    0.771654424224568, 0.782615023307232, 0.793369058840623, 0.80392911698997,
    0.814306670135215, 0.824512208752291, 0.834555354086381, 0.844444954909153,
    0.854189171008163, 0.863795545553308, 0.87327106808886, 0.882622229585165,
    0.891855070732941, 0.900975224461221, 0.909987953496718, 0.91889818364959,
    0.927710533401999, 0.936429340286575, 0.945058684468165, 0.953602409881086,
    0.96206414322304, 0.970447311064224, 0.978755155294224, 0.986990747099062,
    0.99515699963509, 1.00325667954467, 1.01129241744, 1.01926671746548,
    1.02718196603564, 1.03504043983344, 1.04284431314415, 1.05059566459093,
    1.05829648333067, 1.06594867476212, 1.07355406579244, 1.0811144097034,
    1.08863139065398, 1.09610662785202, 1.10354167942464, 1.11093804601357,
    1.11829717411934, 1.12562045921553, 1.13290924865253, 1.14016484436815,
    1.14738850542085, 1.15458145035993, 1.16174485944561, 1.16887987673083,
    1.17598761201545, 1.18306914268269, 1.19012551542669, 1.19715774787944,
    1.20416683014438, 1.2111537262437, 1.21811937548548, 1.22506469375653,
    1.23199057474614, 1.23889789110569, 1.24578749554863, 1.2526602218949,
    1.25951688606371, 1.26635828701823, 1.27318520766536, 1.27999841571382,
    1.28679866449324, 1.29358669373695, 1.30036323033084, 1.30712898903073,
    1.31388467315022, 1.32063097522106, 1.32736857762793, 1.33409815321936,
    1.3408203658964, 1.34753587118059, 1.35424531676263, 1.36094934303328,
    1.36764858359748, 1.37434366577317, 1.38103521107586, 1.38772383568998,
    1.39441015092814, 1.40109476367925, 1.4077782768464, 1.41446128977547,
    1.42114439867531, 1.42782819703026, 1.43451327600589, 1.44120022484872,
    1.44788963128058, 1.45458208188841, 1.46127816251028, 1.46797845861808,
    1.47468355569786, 1.48139403962819, 1.48811049705745, 1.49483351578049,
    1.50156368511546, 1.50830159628131, 1.51504784277671, 1.521803020761,
    1.52856772943771, 1.53534257144151, 1.542128153229, 1.54892508547417,
    1.55573398346918, 1.56255546753104, 1.56939016341512, 1.57623870273591,
    1.58310172339603, 1.58997987002419, 1.59687379442279, 1.60378415602609,
    1.61071162236983, 1.61765686957301, 1.62462058283303, 1.63160345693487,
    1.63860619677555, 1.64562951790478, 1.65267414708306, 1.65974082285818,
    1.66683029616166, 1.67394333092612, 1.68108070472517, 1.68824320943719,
    1.69543165193456, 1.70264685479992, 1.7098896570713, 1.71716091501782,
    1.72446150294804, 1.73179231405296, 1.73915426128591, 1.74654827828172,
    1.75397532031767, 1.76143636531891, 1.76893241491127, 1.77646449552452,
    1.78403365954944, 1.79164098655216, 1.79928758454972, 1.80697459135082,
    1.81470317596628, 1.82247454009388, 1.83028991968276, 1.83815058658281,
    1.84605785028518, 1.8540130597602, 1.86201760539967, 1.87007292107127,
    1.878180486293, 1.88634182853678, 1.8945585256707, 1.90283220855043,
    1.91116456377125, 1.91955733659319, 1.92801233405266, 1.93653142827569,
    1.94511656000868, 1.95376974238465, 1.96249306494436, 1.97128869793366,
    1.98015889690048, 1.98910600761744, 1.99813247135842, 2.00724083056053,
    2.0164337349062, 2.02571394786385, 2.03508435372962, 2.04454796521753,
    2.05410793165065, 2.06376754781173, 2.07353026351874, 2.0833996939983,
    2.09337963113879, 2.10347405571488, 2.11368715068665, 2.12402331568952,
    2.13448718284602, 2.14508363404789, 2.15581781987674, 2.16669518035431,
    2.17772146774029, 2.18890277162636, 2.20024554661128, 2.21175664288416,
    2.22344334009251, 2.23531338492992, 2.24737503294739, 2.25963709517379,
    2.27210899022838, 2.28480080272449, 2.29772334890286, 2.31088825060137,
    2.32430801887113, 2.33799614879653, 2.35196722737914, 2.36623705671729,
    2.38082279517208, 2.39574311978193, 2.41101841390112, 2.42667098493715,
    2.44272531820036, 2.4592083743347, 2.47614993967052, 2.49358304127105,
    2.51154444162669, 2.53007523215985, 2.54922155032478, 2.56903545268184,
    2.58957598670829, 2.61091051848882, 2.63311639363158, 2.65628303757674,
    2.68051464328574, 2.70593365612306, 2.73268535904401, 2.76094400527999,
    2.79092117400193, 2.82287739682644, 2.85713873087322, 2.89412105361341,
    2.93436686720889, 2.97860327988184, 3.02783779176959, 3.08352613200214,
    3.147889289518, 3.2245750520478, 3.32024473383983, 3.44927829856143,
    3.65415288536101, 3.91075795952492 };

  static real_T c4_dv1[257] = { 1.0, 0.977101701267673, 0.959879091800108,
    0.9451989534423, 0.932060075959231, 0.919991505039348, 0.908726440052131,
    0.898095921898344, 0.887984660755834, 0.878309655808918, 0.869008688036857,
    0.860033621196332, 0.851346258458678, 0.842915653112205, 0.834716292986884,
    0.826726833946222, 0.818929191603703, 0.811307874312656, 0.803849483170964,
    0.796542330422959, 0.789376143566025, 0.782341832654803, 0.775431304981187,
    0.768637315798486, 0.761953346836795, 0.755373506507096, 0.748892447219157,
    0.742505296340151, 0.736207598126863, 0.729995264561476, 0.72386453346863,
    0.717811932630722, 0.711834248878248, 0.705928501332754, 0.700091918136512,
    0.694321916126117, 0.688616083004672, 0.682972161644995, 0.677388036218774,
    0.671861719897082, 0.66639134390875, 0.660975147776663, 0.655611470579697,
    0.650298743110817, 0.645035480820822, 0.639820277453057, 0.634651799287624,
    0.629528779924837, 0.624450015547027, 0.619414360605834, 0.614420723888914,
    0.609468064925773, 0.604555390697468, 0.599681752619125, 0.594846243767987,
    0.590047996332826, 0.585286179263371, 0.580559996100791, 0.575868682972354,
    0.571211506735253, 0.566587763256165, 0.561996775814525, 0.557437893618766,
    0.552910490425833, 0.548413963255266, 0.543947731190026, 0.539511234256952,
    0.535103932380458, 0.530725304403662, 0.526374847171684, 0.522052074672322,
    0.517756517229756, 0.513487720747327, 0.509245245995748, 0.505028667943468,
    0.500837575126149, 0.49667156905249, 0.492530263643869, 0.488413284705458,
    0.484320269426683, 0.480250865909047, 0.476204732719506, 0.47218153846773,
    0.468180961405694, 0.464202689048174, 0.460246417812843, 0.456311852678716,
    0.452398706861849, 0.448506701507203, 0.444635565395739, 0.440785034665804,
    0.436954852547985, 0.433144769112652, 0.429354541029442, 0.425583931338022,
    0.421832709229496, 0.418100649837848, 0.414387534040891, 0.410693148270188,
    0.407017284329473, 0.403359739221114, 0.399720314980197, 0.396098818515832,
    0.392495061459315, 0.388908860018789, 0.385340034840077, 0.381788410873393,
    0.378253817245619, 0.374736087137891, 0.371235057668239, 0.367750569779032,
    0.364282468129004, 0.360830600989648, 0.357394820145781, 0.353974980800077,
    0.350570941481406, 0.347182563956794, 0.343809713146851, 0.340452257044522,
    0.337110066637006, 0.333783015830718, 0.330470981379163, 0.327173842813601,
    0.323891482376391, 0.320623784956905, 0.317370638029914, 0.314131931596337,
    0.310907558126286, 0.307697412504292, 0.30450139197665, 0.301319396100803,
    0.298151326696685, 0.294997087799962, 0.291856585617095, 0.288729728482183,
    0.285616426815502, 0.282516593083708, 0.279430141761638, 0.276356989295668,
    0.273297054068577, 0.270250256365875, 0.267216518343561, 0.264195763997261,
    0.261187919132721, 0.258192911337619, 0.255210669954662, 0.252241126055942,
    0.249284212418529, 0.246339863501264, 0.24340801542275, 0.240488605940501,
    0.237581574431238, 0.23468686187233, 0.231804410824339, 0.228934165414681,
    0.226076071322381, 0.223230075763918, 0.220396127480152, 0.217574176724331,
    0.214764175251174, 0.211966076307031, 0.209179834621125, 0.206405406397881,
    0.203642749310335, 0.200891822494657, 0.198152586545776, 0.195425003514135,
    0.192709036903589, 0.190004651670465, 0.187311814223801, 0.1846304924268,
    0.181960655599523, 0.179302274522848, 0.176655321443735, 0.174019770081839,
    0.171395595637506, 0.168782774801212, 0.166181285764482, 0.163591108232366,
    0.161012223437511, 0.158444614155925, 0.15588826472448, 0.153343161060263,
    0.150809290681846, 0.148286642732575, 0.145775208005994, 0.143274978973514,
    0.140785949814445, 0.138308116448551, 0.135841476571254, 0.133386029691669,
    0.130941777173644, 0.12850872228, 0.126086870220186, 0.123676228201597,
    0.12127680548479, 0.11888861344291, 0.116511665625611, 0.114145977827839,
    0.111791568163838, 0.109448457146812, 0.107116667774684, 0.104796225622487,
    0.102487158941935, 0.10018949876881, 0.0979032790388625, 0.095628536713009,
    0.093365311912691, 0.0911136480663738, 0.0888735920682759,
    0.0866451944505581, 0.0844285095703535, 0.082223595813203,
    0.0800305158146631, 0.0778493367020961, 0.0756801303589272,
    0.0735229737139814, 0.0713779490588905, 0.0692451443970068,
    0.0671246538277886, 0.065016577971243, 0.0629210244377582, 0.06083810834954,
    0.0587679529209339, 0.0567106901062031, 0.0546664613248891,
    0.0526354182767924, 0.0506177238609479, 0.0486135532158687,
    0.0466230949019305, 0.0446465522512946, 0.0426841449164746,
    0.0407361106559411, 0.0388027074045262, 0.0368842156885674,
    0.0349809414617162, 0.0330932194585786, 0.0312214171919203,
    0.0293659397581334, 0.0275272356696031, 0.0257058040085489,
    0.0239022033057959, 0.0221170627073089, 0.0203510962300445,
    0.0186051212757247, 0.0168800831525432, 0.0151770883079353,
    0.0134974506017399, 0.0118427578579079, 0.0102149714397015,
    0.00861658276939875, 0.00705087547137324, 0.00552240329925101,
    0.00403797259336304, 0.00260907274610216, 0.0012602859304986,
    0.000477467764609386 };

  emlrtStack c4_b_st;
  emlrtStack c4_st;
  real_T c4_b_r;
  real_T c4_b_u;
  real_T c4_b_x;
  real_T c4_c_u;
  real_T c4_c_x;
  real_T c4_d_u;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_u;
  real_T c4_x;
  real_T c4_y;
  int32_T c4_exitg1;
  uint32_T c4_u32[2];
  uint32_T c4_i;
  uint32_T c4_ip1;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_gb_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  do {
    c4_exitg1 = 0;
    c4_b_st.site = &c4_hb_emlrtRSI;
    c4_b_genrand_uint32_vector(chartInstance, c4_e_state, c4_u32);
    c4_i = (c4_u32[1] >> 24U) + 1U;
    c4_ip1 = c4_i + 1U;
    c4_u = ((real_T)(c4_u32[0] >> 3U) * 1.6777216E+7 + (real_T)(c4_u32[1] &
             16777215U)) * 2.2204460492503131E-16 - 1.0;
    c4_b_r = c4_u * c4_dv[(int32_T)c4_ip1 - 1];
    c4_x = c4_b_r;
    c4_b_x = c4_x;
    c4_c_x = c4_b_x;
    c4_y = muDoubleScalarAbs(c4_c_x);
    if (c4_y <= c4_dv[(int32_T)c4_i - 1]) {
      c4_exitg1 = 1;
    } else if ((real_T)c4_i < 256.0) {
      c4_b_st.site = &c4_ib_emlrtRSI;
      c4_b_u = c4_c_genrandu(chartInstance, &c4_b_st, c4_e_state);
      c4_d_x = -0.5 * c4_b_r * c4_b_r;
      c4_f_x = c4_d_x;
      c4_f_x = muDoubleScalarExp(c4_f_x);
      if (c4_dv1[(int32_T)c4_ip1 - 1] + c4_b_u * (c4_dv1[(int32_T)c4_i - 1] -
           c4_dv1[(int32_T)c4_ip1 - 1]) < c4_f_x) {
        c4_exitg1 = 1;
      }
    } else {
      do {
        c4_b_st.site = &c4_jb_emlrtRSI;
        c4_c_u = c4_c_genrandu(chartInstance, &c4_b_st, c4_e_state);
        c4_e_x = muDoubleScalarLog(c4_c_u) * 0.273661237329758;
        c4_b_st.site = &c4_kb_emlrtRSI;
        c4_d_u = c4_c_genrandu(chartInstance, &c4_b_st, c4_e_state);
      } while (!(-2.0 * muDoubleScalarLog(c4_d_u) > c4_e_x * c4_e_x));

      if (c4_b_r < 0.0) {
        c4_b_r = c4_e_x - 3.65415288536101;
      } else {
        c4_b_r = 3.65415288536101 - c4_e_x;
      }

      c4_exitg1 = 1;
    }
  } while (c4_exitg1 == 0);

  return c4_b_r;
}

static void c4_b_genrand_uint32_vector(SFc4_dataInstanceStruct *chartInstance,
  uint32_T c4_mt[625], uint32_T c4_u[2])
{
  real_T c4_b_j;
  real_T c4_c_kk;
  int32_T c4_b_kk;
  int32_T c4_j;
  int32_T c4_kk;
  uint32_T c4_b_y;
  uint32_T c4_c_y;
  uint32_T c4_d_y;
  uint32_T c4_e_y;
  uint32_T c4_f_y;
  uint32_T c4_g_y;
  uint32_T c4_mti;
  uint32_T c4_y;
  (void)chartInstance;
  for (c4_j = 0; c4_j < 2; c4_j++) {
    c4_b_j = 1.0 + (real_T)c4_j;
    c4_mti = c4_mt[624] + 1U;
    if ((real_T)c4_mti >= 625.0) {
      for (c4_kk = 0; c4_kk < 227; c4_kk++) {
        c4_c_kk = 1.0 + (real_T)c4_kk;
        c4_y = (c4_mt[(int32_T)c4_c_kk - 1] & 2147483648U) | (c4_mt[(int32_T)
          (c4_c_kk + 1.0) - 1] & 2147483647U);
        c4_b_y = c4_y;
        c4_d_y = c4_b_y;
        if ((c4_d_y & 1U) == 0U) {
          c4_d_y >>= 1U;
        } else {
          c4_d_y = c4_d_y >> 1U ^ 2567483615U;
        }

        c4_mt[(int32_T)c4_c_kk - 1] = c4_mt[(int32_T)(c4_c_kk + 397.0) - 1] ^
          c4_d_y;
      }

      for (c4_b_kk = 0; c4_b_kk < 396; c4_b_kk++) {
        c4_c_kk = 228.0 + (real_T)c4_b_kk;
        c4_y = (c4_mt[(int32_T)c4_c_kk - 1] & 2147483648U) | (c4_mt[(int32_T)
          (c4_c_kk + 1.0) - 1] & 2147483647U);
        c4_f_y = c4_y;
        c4_g_y = c4_f_y;
        if ((c4_g_y & 1U) == 0U) {
          c4_g_y >>= 1U;
        } else {
          c4_g_y = c4_g_y >> 1U ^ 2567483615U;
        }

        c4_mt[(int32_T)c4_c_kk - 1] = c4_mt[(int32_T)((c4_c_kk + 1.0) - 228.0) -
          1] ^ c4_g_y;
      }

      c4_y = (c4_mt[623] & 2147483648U) | (c4_mt[0] & 2147483647U);
      c4_c_y = c4_y;
      c4_e_y = c4_c_y;
      if ((c4_e_y & 1U) == 0U) {
        c4_e_y >>= 1U;
      } else {
        c4_e_y = c4_e_y >> 1U ^ 2567483615U;
      }

      c4_mt[623] = c4_mt[396] ^ c4_e_y;
      c4_mti = 1U;
    }

    c4_y = c4_mt[(int32_T)c4_mti - 1];
    c4_mt[624] = c4_mti;
    c4_y ^= c4_y >> 11U;
    c4_y ^= c4_y << 7U & 2636928640U;
    c4_y ^= c4_y << 15U & 4022730752U;
    c4_y ^= c4_y >> 18U;
    c4_u[(int32_T)c4_b_j - 1] = c4_y;
  }
}

static real_T c4_c_genrandu(SFc4_dataInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, uint32_T c4_mt[625])
{
  static char_T c4_cv[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  const mxArray *c4_b_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_r;
  int32_T c4_a;
  int32_T c4_exitg1;
  int32_T c4_i;
  int32_T c4_k;
  uint32_T c4_b_mt[625];
  uint32_T c4_u[2];
  boolean_T c4_b_isvalid;
  boolean_T c4_exitg2;
  boolean_T c4_isvalid;

  /* ========================= COPYRIGHT NOTICE ============================ */
  /*  This is a uniform (0,1) pseudorandom number generator based on:        */
  /*                                                                         */
  /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
  /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
  /*                                                                         */
  /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
  /*  All rights reserved.                                                   */
  /*                                                                         */
  /*  Redistribution and use in source and binary forms, with or without     */
  /*  modification, are permitted provided that the following conditions     */
  /*  are met:                                                               */
  /*                                                                         */
  /*    1. Redistributions of source code must retain the above copyright    */
  /*       notice, this list of conditions and the following disclaimer.     */
  /*                                                                         */
  /*    2. Redistributions in binary form must reproduce the above copyright */
  /*       notice, this list of conditions and the following disclaimer      */
  /*       in the documentation and/or other materials provided with the     */
  /*       distribution.                                                     */
  /*                                                                         */
  /*    3. The names of its contributors may not be used to endorse or       */
  /*       promote products derived from this software without specific      */
  /*       prior written permission.                                         */
  /*                                                                         */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
  /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
  /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
  /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
  /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
  /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
  /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
  /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
  /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
  /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
  /*                                                                         */
  /* =============================   END   ================================= */
  do {
    c4_exitg1 = 0;
    c4_b_genrand_uint32_vector(chartInstance, c4_mt, c4_u);
    c4_u[0] >>= 5U;
    c4_u[1] >>= 6U;
    c4_r = 1.1102230246251565E-16 * ((real_T)c4_u[0] * 6.7108864E+7 + (real_T)
      c4_u[1]);
    if (c4_r == 0.0) {
      for (c4_i = 0; c4_i < 625; c4_i++) {
        c4_b_mt[c4_i] = c4_mt[c4_i];
      }

      if (((real_T)c4_b_mt[624] >= 1.0) && ((real_T)c4_b_mt[624] < 625.0)) {
        c4_isvalid = true;
      } else {
        c4_isvalid = false;
      }

      c4_b_isvalid = c4_isvalid;
      if (c4_isvalid) {
        c4_b_isvalid = false;
        c4_k = 0;
        c4_exitg2 = false;
        while ((!c4_exitg2) && (c4_k + 1 < 625)) {
          if ((real_T)c4_b_mt[c4_k] == 0.0) {
            c4_a = c4_k + 1;
            c4_k = c4_a;
          } else {
            c4_b_isvalid = true;
            c4_exitg2 = true;
          }
        }
      }

      if (!c4_b_isvalid) {
        c4_y = NULL;
        sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 37),
                      false);
        c4_b_y = NULL;
        sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1,
          37), false);
        sf_mex_call(c4_sp, &c4_b_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                    sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(c4_sp, NULL, "message", 1U, 1U, 14, c4_b_y)));
      }
    } else {
      c4_exitg1 = 1;
    }
  } while (c4_exitg1 == 0);

  return c4_r;
}

static real_T c4_get_a(SFc4_dataInstanceStruct *chartInstance, uint32_T
  c4_elementIndex)
{
  if (chartInstance->c4_dsmdiag_a) {
    ssReadFromDataStoreElement_wrapper(chartInstance->S, 0, "a", c4_elementIndex);
  }

  return (*chartInstance->c4_a_address)[c4_elementIndex];
}

static void c4_set_a(SFc4_dataInstanceStruct *chartInstance, uint32_T
                     c4_elementIndex, real_T c4_elementValue)
{
  if (chartInstance->c4_dsmdiag_a) {
    ssWriteToDataStoreElement_wrapper(chartInstance->S, 0, "a", c4_elementIndex);
  }

  (*chartInstance->c4_a_address)[c4_elementIndex] = c4_elementValue;
}

static real_T *c4_access_a(SFc4_dataInstanceStruct *chartInstance, uint32_T
  c4_rdOnly)
{
  if (chartInstance->c4_dsmdiag_a) {
    ssAccessDataStore_wrapper(chartInstance->S, 0, "a", c4_rdOnly);
  }

  return &(*chartInstance->c4_a_address)[0U];
}

static real_T c4_get_b(SFc4_dataInstanceStruct *chartInstance, uint32_T
  c4_elementIndex)
{
  if (chartInstance->c4_dsmdiag_b) {
    ssReadFromDataStoreElement_wrapper(chartInstance->S, 1, "b", c4_elementIndex);
  }

  return (*chartInstance->c4__indexb_address)[c4_elementIndex];
}

static void c4_set_b(SFc4_dataInstanceStruct *chartInstance, uint32_T
                     c4_elementIndex, real_T c4_elementValue)
{
  if (chartInstance->c4_dsmdiag_b) {
    ssWriteToDataStoreElement_wrapper(chartInstance->S, 1, "b", c4_elementIndex);
  }

  (*chartInstance->c4__indexb_address)[c4_elementIndex] = c4_elementValue;
}

static real_T *c4_access_b(SFc4_dataInstanceStruct *chartInstance, uint32_T
  c4_rdOnly)
{
  if (chartInstance->c4_dsmdiag_b) {
    ssAccessDataStore_wrapper(chartInstance->S, 1, "b", c4_rdOnly);
  }

  return &(*chartInstance->c4__indexb_address)[0U];
}

static real_T c4_get_f(SFc4_dataInstanceStruct *chartInstance, uint32_T
  c4_elementIndex)
{
  if (chartInstance->c4_dsmdiag_f) {
    ssReadFromDataStoreElement_wrapper(chartInstance->S, 2, "f", c4_elementIndex);
  }

  return (*chartInstance->c4__indexf_address)[c4_elementIndex];
}

static void c4_set_f(SFc4_dataInstanceStruct *chartInstance, uint32_T
                     c4_elementIndex, real_T c4_elementValue)
{
  if (chartInstance->c4_dsmdiag_f) {
    ssWriteToDataStoreElement_wrapper(chartInstance->S, 2, "f", c4_elementIndex);
  }

  (*chartInstance->c4__indexf_address)[c4_elementIndex] = c4_elementValue;
}

static real_T *c4_access_f(SFc4_dataInstanceStruct *chartInstance, uint32_T
  c4_rdOnly)
{
  if (chartInstance->c4_dsmdiag_f) {
    ssAccessDataStore_wrapper(chartInstance->S, 2, "f", c4_rdOnly);
  }

  return &(*chartInstance->c4__indexf_address)[0U];
}

static void init_dsm_address_info(SFc4_dataInstanceStruct *chartInstance)
{
  ssGetSFcnPrimitiveDataStoreNameAddrIdx_wrapper(chartInstance->S, "a", (void **)
    &chartInstance->c4_a_address, &chartInstance->c4__index);
  ssGetSFcnPrimitiveDataStoreNameAddrIdx_wrapper(chartInstance->S, "b", (void **)
    &chartInstance->c4__indexb_address, &chartInstance->c4_b__index);
  ssGetSFcnPrimitiveDataStoreNameAddrIdx_wrapper(chartInstance->S, "f", (void **)
    &chartInstance->c4__indexf_address, &chartInstance->c4_c__index);
}

static void init_simulink_io_address(SFc4_dataInstanceStruct *chartInstance)
{
  chartInstance->c4_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_t = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c4_q = (real_T (*)[7])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_qd = (real_T (*)[7])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c4_qdd = (real_T (*)[7])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c4_dsmdiag_a = (boolean_T)
    ssGetDSMBlockDiagnosticsEnabled_wrapper(chartInstance->S, 0, "a");
  chartInstance->c4_dsmdiag_b = (boolean_T)
    ssGetDSMBlockDiagnosticsEnabled_wrapper(chartInstance->S, 1, "b");
  chartInstance->c4_dsmdiag_f = (boolean_T)
    ssGetDSMBlockDiagnosticsEnabled_wrapper(chartInstance->S, 2, "f");
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c4_data_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2457106113U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2875527397U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3653141884U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2664938941U);
}

mxArray *sf_c4_data_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_data_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("time");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c4_data_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_data(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiB+IMjAwAakOYCYiQECWKF8RiDmhtIQcRa4uAIQl1QWpILEi4uSPVOAdF5iLpi"
    "fWFrhmZeWDzbfggFhPhsW8xmRzOeEikPAB3vK9Is4gPQbIOlnIaBfAMgqhIYLLHwGzv0SRLmfCc"
    "X9TAyFKYPF/TJEuZ8Zxf3MQPenUMn9Ag6U6ce0H5v72VDcD+HnppZk5EPjwYERf/5iRMtfTEjm5"
    "jBkMhRA3eFAwB9MaP4QgHkiosEBTHc0OFAjPRQQCA97tPAA8V2sYnwTS3ISk4wMjAxjSvLzc5Ly"
    "K2JSc3NicjKTYnLBUjFFiXkpaaV5MQVFmWWJJakg6XiQmF7uaDqgSjpohaaDVrqkAwe08HCgNB3"
    "k6eUOhnRAqDxjQfE3C0NxamoK2N6Bjv8XEyDx/2MCVeI/g0A4GKHFvxGp8V+Ulw7M+kOmHmBF8y"
    "+IX1wCTMBQ/REDHf8LUiDx75BKlfjvIBAegWjhEUhp/o/PTU43NLMwMI8HB2taaQ4seYymD2qkj"
    "wPQ9JFAn/QRhBYeQZSnjxJDS0tj88QijAQymj5Gy4+U+OKMIuPk/Lz04Vl+DHj7cgK0fbljpLYv"
    "FaiSDjwI+FsQzd8gfmZxfGJySWZZanyySXxKYkkiknkgAABtuyny"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_data_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "ssvSPTDWuy6erde3GE1Gn3";
}

static void sf_opaque_initialize_c4_data(void *chartInstanceVar)
{
  initialize_params_c4_data((SFc4_dataInstanceStruct*) chartInstanceVar);
  initialize_c4_data((SFc4_dataInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_data(void *chartInstanceVar)
{
  enable_c4_data((SFc4_dataInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_data(void *chartInstanceVar)
{
  disable_c4_data((SFc4_dataInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_data(void *chartInstanceVar)
{
  sf_gateway_c4_data((SFc4_dataInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_data(SimStruct* S)
{
  return get_sim_state_c4_data((SFc4_dataInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_data(SimStruct* S, const mxArray *st)
{
  set_sim_state_c4_data((SFc4_dataInstanceStruct*)sf_get_chart_instance_ptr(S),
                        st);
}

static void sf_opaque_cleanup_runtime_resources_c4_data(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_dataInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_data_optimization_info();
    }

    mdl_cleanup_runtime_resources_c4_data((SFc4_dataInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c4_data(void *chartInstanceVar)
{
  mdl_start_c4_data((SFc4_dataInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c4_data(void *chartInstanceVar)
{
  mdl_terminate_c4_data((SFc4_dataInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_data((SFc4_dataInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_data(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_data((SFc4_dataInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc4_data((SFc4_dataInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c4_data_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [24] = {
    "eNrtWb1vI0UUXztORHQQEoROFCcRaKCK8oHug4LzxR+HpZjk4uTuCktmvPvsHXl3ZjMz6yTdNSe",
    "dhJBS0SHR8D9QXoHEv0BJSUFBScmb9Tpx1rveJDZJuMtK6/Xs/N6b9/GbN+OxkalUDbzm8F781D",
    "Bm8PkO3lmjd02H7czA3XufMz4L29+jEPPdLSKIK42RFyMubIPkjq8oZxXW4rEwyloggJmI9bhQS",
    "dokdX2Hsk7ZZ6bWJ5/Z1LRrNvcdax1libXJnEPU5vlqC/UUqQBTlQEsZQvut+2yQ9rHFgu1X7DB",
    "7EjfHeWCBFXzPW2WrPqOop4DpQMwK0wqghbLE9tqiigoqINEN7WnstYHctdzKGGx3tpE1sDDACv",
    "Y9Sz83PQVOhWFmTYRah1s0gW5QTuBTs4gqpNK7GhSRhQXlDgl1ylowWHbthy0p8otcEYEBG1bF0",
    "A6HqdMJee/VkZPS4w0HShC028na6vBnq+T/5TCPojEuLUKvAuCtGGTJQ4aBKR0EGTrmCXDMEVde",
    "ErEIxPzJ8FKZC8yR9YI5gl2UCIJBoGTFbkjaBfDm6jNdyuamWlTxnd7yZZpsEBbqQujsnCsrWyy",
    "AnEcmQjb4d4GdMEJtBaJIqNhPa3xOCmptcMxwJreybPBZxQTH8IKnFk0Nl3dCCCoO99gYTmNNH2",
    "puFtA8hY3Noa7h2EVpkC0iAlxVUAQKgFjFoQ3WZtFpc49AtEqFZgXB+4xJA1lyJbPivtcdDAmI4",
    "rIiQs6o4lAV7YxlzgTdiVOmlEwncs0nElMGyxdYKgDVZw2iI2JidSl7RHOuy5Vh0WQpqBeTFZ9n",
    "HVYhkqaUIce7LIO4/usLLhbC2t8L7wAyDYiGGXtdaxf4rCMo8elQq9ny8bJevbuGdazvlz0+fmA",
    "nkyMHmPgGR13Njt63Cx+y4Ry+QG59yLj5CJyGjeP963bP//2upr/YfmvX5s/vv/JdxcZv2/30Qf",
    "nW//nwvadfqE9njjdIb5q7NcDduVi9N8e0D8ftqXs1rZ2is/8w7sgLFh7XFp5zNZ6+v5YGG3vrY",
    "i9/feLuuIjywJ+CrNihRsT3SZ+b7nW+u8P2DuTEo/Z8H3v+vvhePIf5qN5zKXIz+O3vQhvr87+j",
    "85kf/aU/Vljz7ou9t85k/1Tp+yfQvutCdk/nx9Pfnj8OPtnIvNNt11QNg/zkM+crx5kB/Q6BjW8",
    "mLo2k8KD2dCW4Hr+Ih88X73IT4IPXko8HkbiodvFL+tVohzSXF1eXakrzp0mP6iD69Qd2qy7QVd",
    "dEGbhUl33cMOHy53ubuh3S+4NDybCg5chD15eCg/ykXjkx+UBW3KvAw/S6lnulN85/KULVjDuVe",
    "f/z6Ne/v85mkj+7ZQ4rEbyv3re/AvWXnL/P+vAdMTf6f6+PZR/ftX5/8nq5T8PE8n/q5R4PInE4",
    "8m487/hmu2Vu/eX7zWCsLZ8p0+PG35Mgh+vQ358ezn82I7EY3t8fqiVBw/W7hExRJAbftzUD6sh",
    "bbFmctZ+M+vHle8vj8L95S9v6/5ycSI8SDvfWYj4vRCc4zeIPh2EhvlFwzo5PZ6bwHnaRc/BbuS",
    "uVi7zFvp3lvPpi8pNjXkeflly4/p33nP664Yf9fvciODnr7Ef4/5/8l/jfzfOt9/4OGx/dfxXZs",
    "GmjhXzr1bYvQGkFdf7BvD0X417v3s=",
    ""
  };

  static char newstr [1681] = "";
  newstr[0] = '\0';
  for (i = 0; i < 24; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c4_data(SimStruct *S)
{
  const char* newstr = sf_c4_data_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(3349485067U));
  ssSetChecksum1(S,(2520796608U));
  ssSetChecksum2(S,(1657072688U));
  ssSetChecksum3(S,(2334199709U));
}

static void mdlRTW_c4_data(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c4_data(SimStruct *S)
{
  SFc4_dataInstanceStruct *chartInstance;
  chartInstance = (SFc4_dataInstanceStruct *)utMalloc(sizeof
    (SFc4_dataInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_dataInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  if (ssGetSampleTime(S, 0) == CONTINUOUS_SAMPLE_TIME && ssGetOffsetTime(S, 0) ==
      0 && ssGetNumContStates(ssGetRootSS(S)) > 0 &&
      !supportsLegacyBehaviorForPersistentVarInContinuousTime(S)) {
    sf_error_out_about_continuous_sample_time_with_persistent_vars(S);
  }

  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_data;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_data;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c4_data;
  chartInstance->chartInfo.mdlTerminate = sf_opaque_mdl_terminate_c4_data;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c4_data;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_data;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_data;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_data;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_data;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_data;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_data;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_data;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.chartStateSetterFcn = NULL;
  chartInstance->chartInfo.chartStateGetterFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c4_JITStateAnimation,
    chartInstance->c4_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c4_data(chartInstance);
}

void c4_data_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c4_data(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_data(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_data(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_data_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
