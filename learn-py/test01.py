import urllib2 as ul2;
import urllib as ul;

url = 'http://poj.org';

# 使用 url 得到 response
def main1():
  response = ul2.urlopen(url);
  html = response.read();
  print html;

# 用 requset 得到 response
def main2():
  request = ul2.Request(url);
  response = ul2.urlopen(request);
  html = response.read();
  print html;

# urlencode 將一個 dict 編碼成標準形式
def main3():
  values = {'name' : 'mu', 'location' : 'ccnu', 'language' : 'python'};
  data = ul.urlencode(values);
  print data; # name=mu&language=python&location=ccnu
