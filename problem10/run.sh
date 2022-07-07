t_flag=''

print_usage() {
  printf "Usage: ./run.sh [-t] program_arg\n"
  printf "Optional flag -t tees into README\n"
}

while getopts 't' flag; do
  case "${flag}" in
    t) t_flag=true ;;
    *) print_usage
       exit 1 ;;
  esac
done
shift "$(($OPTIND -1))"

if [ "$t_flag" = true ]; then
  $(echo '```' >> ./README.md)
  $(echo "  Args: $@" | tr -d "\n" >> ./README.md)
  ./build/Problem "$@" | tee -a ./README.md
  $(echo '```' >> README.md)
else
  ./build/Problem "$@"
fi

