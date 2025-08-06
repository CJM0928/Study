날짜와 시간 정보를 다룰 때 필수적인 클래스

    DateTime.Today

        var today = DateTime.Today;
        var seireki = today.Year;
        var heisei = seireki - 1988;
        Console.Write("西暦"+seireki+"年は、");
        Console.WriteLine("平成"+heisei+"年です。");

        // 기대하는 출력값
        // 西暦2025年は、平成37年です。

        DateTime 클래스의 정적(static) 속성
        "오늘 날짜"를 가져오되, 시간은 00:00:00으로 초기화된 상태를 반환


  DateTime.Now와 차이점
  
            속성	                  설명	                시간 포함 여부
        DateTime.Today	  오늘 날짜 (자정 시간)	      항상 00:00:00
        DateTime.Now	  현재 날짜와 시간	      현재 시/분/초 포함

        
  자주 쓰는 DateTime 형식 메서드들
  
      기능	                        예시
    연도 구하기	            today.Year → 2025
    월 구하기	            today.Month → 8
    일 구하기	            today.Day → 6
    요일 구하기	            today.DayOfWeek → Wednesday
    문자열 포맷	            today.ToString("yyyy/MM/dd")

  Java 비교
  
        C#	                          Java
    DateTime.Today	               LocalDate.now()
    .Year	                      .getYear()
    .Month	                      .getMonthValue()
    .Day	                      .getDayOfMonth()
