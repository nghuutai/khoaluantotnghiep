# khoaluantotnghiep
Thư mục datatest chứa 2 file testcase.txt, test.txt
  File testcase.txt: dòng đầu tiên cho biết số bộ test, các dòng tiếp theo cứ 3 dòng là 1 bộ test case.
  File test.txt: chứa bộ test case cho mỗi lần test.

File solution.c: lời giải gốc của bài tập
File sv.c: file sinh viên nộp
File out.txt: lưu kết quả sau khi thực thi của file solution.c
file outsv.txt: lưu kết quả sau khi thực thi của file sv.c
File run.c: file thực hiện chấm điểm bài nộp của sinh viên dựa trên solution và các bộ testcase.
Cách chạy chương trình: mở của sổ commandline và gõ 2 lệnh sau
  gcc -Wall -o run run.c
  ./run
