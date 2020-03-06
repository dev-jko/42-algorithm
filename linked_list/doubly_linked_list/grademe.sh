dir=`dirname $0`

gcc *.c $dir/grademe_files/test.c -I.

if [ ! -e ./a.out ] ; then
	echo "컴파일 에러"
	exit 1
fi
./a.out > user_output

echo "\n============ check diff ================"
if [ ! -e $dir/grademe_files/doubly_linked_list_output ] ; then
	echo "doubly_linked_list_output 파일이 없습니다."
else
	diff user_output $dir/grademe_files/doubly_linked_list_output
fi

echo "\n============ check leaks ==============="
if [ ! -e ./leaks_result ] ; then
	echo "leaks check 결과 파일이 없습니다"
else
	cat leaks_result | grep leaked
fi

rm user_output a.out leaks_result
echo "\n================ end ==================="
