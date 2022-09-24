with import <nixpkgs> {};

stdenv.mkDerivation {
  name = "acl";
  buildInputs = [gcc acl];
} 
