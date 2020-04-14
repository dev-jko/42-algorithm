# Quick Sort

[뒤로 가기](..)

## exercise 00
- allowed functions : malloc, free
- quick sort를 구현 합니다.

### quick_sort
- quick sort를 사용하여 items를 오름차순으로 정렬하는 함수를 작성하세요.
- items는 size 갯수의 item으로 이루어져있습니다.
- cmp는 item을 비교하는데 사용 됩니다. 첫번째 인자가 더 크면 양수, 작으면 음수, 같다면 0을 반환 합니다.
- 성공 시 1, 실패 시 0을 반환 합니다.
	```
	int	quick_sort(void **items, int size, int (*cmp)(void *, void *));
	```

[뒤로 가기](..)
