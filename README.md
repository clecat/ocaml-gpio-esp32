# ocaml-gpio-esp32
GPIO driver for esp32 in OCaml

Actually consist in stubs linking esp-idf C code with OCaml module (I suppose the long-term goal is to have a fully OCaml code, but keeping the original C code may allow us to keep it up to date more easily).

Interupts handling is missing, but for now you can do some basic stuf with those pins