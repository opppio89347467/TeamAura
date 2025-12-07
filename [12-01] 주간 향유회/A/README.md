#  통계
- First solve : Nunu
- 세팅 : TuFuSuHu, IMKERKER
- 검수 : 후회없는진심, ApologyUIIIU, Killonion, TangTangTangShot

# 풀이

- 문자열 S의 모든 경계(prefix == suffix) 길이를 구하려면 KMP의 prefix-function(π 배열)을 사용한다.
- π[n-1]부터 거슬러 올라가면 모든 border 길이가 얻어진다.
- 각 prefix 길이가 부분 문자열로 몇 번 등장하는지는 π 배열 값들을 세고 뒤에서 누적해 계산한다.
- 즉 cnt[l] = 길이 l 접두사가 전체에서 등장한 횟수.
- border 길이별 등장 횟수 cnt[l]을 모아 정렬한다.
- 쿼리 K가 주어지면 cnt[l] >= K인 border 개수를 이분 탐색으로 찾는다.
- 시간 복잡도는 전처리 O(n), 쿼리 O(log n)이다.
