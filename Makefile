protocGenerate: 
	@echo "Removing old generated OCaml files"
	@rm ./proto/*.ml
	@echo "Generating new OCaml files"
	@esy protoc -I protofiles --ocaml_out=./proto-generated $$(find ./protofiles -iname '*.proto')

