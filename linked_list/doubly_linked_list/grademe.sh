dir=`dirname $0`

if [ -e ./a.out ] ; then
	rm a.out
fi
if [ -e ./user_output ] ; then
	rm user_output
fi
if [ -e ./leaks_result ] ; then
	rm leaks_result
fi
gcc -Wall -Wextra -Werror -g *.c $dir/grademe_files/test.c -I.

if [ ! -e ./a.out ] ; then
	echo "컴파일 에러"
	exit 1
fi
./a.out > user_output

echo "============ check diff ================"
if [ ! -e $dir/grademe_files/doubly_linked_list_output ] ; then
	echo "doubly_linked_list_output 파일이 없습니다."
else
	diff user_output $dir/grademe_files/doubly_linked_list_output
fi

echo "============ check leaks ==============="
if [ ! -e ./leaks_result ] ; then
	echo "leaks check 결과 파일이 없습니다"
else
	cat leaks_result | grep leaked
fi
if [ -e ./a.out ] ; then
	rm a.out
fi
if [ -e ./user_output ] ; then
	rm user_output
fi
if [ -e ./leaks_result ] ; then
	rm leaks_result
fi
echo "================ end ==================="
