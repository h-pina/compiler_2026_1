make

if [ "$1" == "" ]; then
	cat <<-EOF
	Por favor, insira o numero do arquivo de teste
	Uso: ./run.sh <numero do teste>
	EOF
	exit 1
fi

./lexer ./tests/test$1.txt
