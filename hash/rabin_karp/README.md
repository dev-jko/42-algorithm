# Rabin-Karp

[뒤로 가기](..)

## exercise 00
- allowed functions : malloc, free
- rabin-karp 알고리즘을 구현 합니다.
- 다음과 같은 해시함수를 사용합니다.
	- `H = S[0] * 302^(l - 1) + S[1] * 302^(l - 2) + ••• + S[l - 2] * 302 + S[l - 1]`
- 값이 너무 커지는 것을 막기 위해 modulo 연산을 활용합니다.
	- `number % 1000000007`


### get_hash_value
- 문자열 str의 hash 값을 구하는 함수를 작성하세요.
- str의 길이와 len 중 작은 값을 길이로 사용합니다.
	```
	long long	get_hash_value(const char *str, unsigned int len);
	```

### find_str
- 문자열 haystack에서 문자열 needle을 찾는 함수 find_str을 작성하세요.
- 일치하는 문자열을 찾으면 시작 주소를, 찾지 못하면 null pointer를 반환 합니다.
	```
	char		*find_str(const char *haystack, const char *needle);
	```


[뒤로 가기](..)
