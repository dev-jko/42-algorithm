subject_output=circular_linked_list_output


dir=`dirname $0`

if [ -e ./a.out ] ; then
	rm -rf a.out a.out.dSYM
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
if [ ! -e $dir/grademe_files/$subject_output ] ; then
	echo "$subject_output 파일이 없습니다."
else
	diff -u user_output $dir/grademe_files/$subject_output | less
fi

echo "============ check leaks ==============="
if [ ! -e ./leaks_result ] ; then
	echo "leaks check 결과 파일이 없습니다"
else
	cat leaks_result | grep leaked
fi
if [ -e ./a.out ] ; then
	rm -rf a.out a.out.dSYM
fi
echo "================ end ==================="
