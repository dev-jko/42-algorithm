gcc *.c
./a.out > user_output

echo "\n============ check diff ================"
diff user_output doubly_linked_list_output

echo "\n============ check leaks ==============="
cat leaks_result | grep leaked


rm user_output a.out leaks_result
echo "\n================ end ==================="
