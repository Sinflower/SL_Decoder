# SL_Decoder

Small program to decode RPG Maker .sl and encode .txt files.

----------

**Usage:**

    sl_dec <sl-file[s]>

Examle (Decode):

    sl_dec 001.sl
    sl_dec 001.sl 002.sl 003.sl
    sl_dec *
    sl_dec scenario/*

Examle (Encode):

    sl_dec 001.txt
    sl_dec 001.txt 002.txt 003.txt
    sl_dec *
    sl_dec scenario/*

----------

Build using MSVC command line:

	cl /O2 sl_dec.cpp /link setargv.obj


***/link setargv.obj*** is required to allow wildcard expansion.