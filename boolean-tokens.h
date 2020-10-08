
#pragma once
    /*  boolean-tokens.h perform boolean operations on tokens
    x,y arguments must be tokens 1,0 
    returned token is 1 for true, and 0 for false
    Macros:
    bool_true(...) always returns 1
    bool_false(...) always returns 0
    bool_id(x) returns 1 if x==1, 0 if x==0
    bool_neg(x) returns 0 if x==1, 1 if x==0

    https://en.wikipedia.org/wiki/Truth_table
    bool_and(x,y) returns (x AND y)
    bool_nand(x,y) returns (x NAND y)
    bool_xor(x,y) returns (x XOR y)
    bool_xnor(x,y) returns (x XNOR y)
    bool_or(x,y) returns (x OR y)
    bool_nor(x,y) returns (x NOR y)

    //en.wikipedia.org/wiki/Converse_implication
    bool_thenif(x,y) returns (x then/if y) 

    //en.wikipedia.org/wiki/Converse_nonimplication
    bool_xq(x,y) returns (x Xq y) 

    //en.wikipedia.org/wiki/Material_implication_(rule_of_inference)
    bool_ifthen(x,y) returns (x ifthen y)

    //en.wikipedia.org/wiki/Material_nonimplication
    bool_adj(x,y) returns (x adj y)

    //en.wikipedia.org/wiki/Projection_function p=proj q=qproj

    bool_proj(x,y) returns (x proj y)
    bool_nproj(x,y) returns (x nproj y)
    bool_qproj(x,y) returns (x qproj y)
    bool_nqproj(x,y) returns (x nqproj y) 



    */
    //==local merge macros
    #define bool_merge2_(a,b) a##b
    #define bool_merge2(a,b) bool_merge2_(a,b)
    #define bool_merge3_(a,b,c) a##b##c
    #define bool_merge3(a,b,c) bool_merge3_(a,b,c)
    #define bool_merge4_(a,b,c,d) a##b##c##d
    #define bool_merge4(a,b,c,d) bool_merge4_(a,b,c,d)


    #define bool_true(...) 1
    #define bool_false(...) 0
    //==unary functions 
    #define bool_id0 0
    #define bool_id1 1
    #define bool_id(v) bool_merge2(bool_id,v)
    #define bool_neg0 1 
    #define bool_neg1 0
    #define bool_neg(v) bool_merge2(bool_neg,v)
    //==Binary functions
    #define bool_and00 0
    #define bool_and01 0
    #define bool_and10 0
    #define bool_and11 1
    #define bool_and(x,y) bool_merge3(bool_and,x,y)
    #define bool_nand(x,y) bool_neg(bool_and(x,y))


    #define bool_xor00 0
    #define bool_xor01 1
    #define bool_xor10 1
    #define bool_xor11 0
    #define bool_xor(x,y) bool_merge3(bool_xor,x,y)
    #define bool_xnor(x,y) bool_neg(bool_xor(x,y))


    #define bool_or00 0
    #define bool_or01 1
    #define bool_or10 1
    #define bool_or11 1
    #define bool_or(x,y) bool_merge3(bool_or,x,y)
    #define bool_nor(x,y) bool_neg(bool_or(x,y)) 



    #define bool_thenif11 1
    #define bool_thenif10 1
    #define bool_thenif01 0
    #define bool_thenif00 1
    #define bool_thenif(x,y) bool_merge3(bool_thenif,x,y)
    #define bool_xq(x,y) bool_neg(bool_thenif(x,y))


    #define bool_ifthen11 1
    #define bool_ifthen10 0
    #define bool_ifthen01 1
    #define bool_ifthen00 1
    #define bool_ifthen(x,y) bool_merge3(bool_ifthen,x,y) 
    #define bool_adj(x,y) bool_neg(bool_ifthen(x,y)) 


    #define bool_proj11 1
    #define bool_proj10 1
    #define bool_proj01 0
    #define bool_proj00 0
    #define bool_proj(x,y) bool_merge3(bool_proj,x,y) 
    #define bool_nproj(x,y) bool_neg(bool_proj(x,y)) 

    #define bool_qproj11 1
    #define bool_qproj10 0
    #define bool_qproj01 1
    #define bool_qproj00 0
    #define bool_qproj(x,y) bool_merge3(bool_qproj,x,y) 
    #define bool_nqproj(x,y) bool_neg(bool_qproj(x,y)) 

