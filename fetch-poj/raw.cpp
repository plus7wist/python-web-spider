#include <string>
#include <fstream>
#include <iostream>

#include <stdio.h>

std::string int2string(int x)
{
  static char buffer[1024];
  sprintf(buffer, "%d", x);
  return std::string(buffer);
}

void remove_link(std::string& html)
{
  std::size_t begin;
  std::size_t end;

  for (; (begin = html.find("<a href")) != std::string::npos; ) {
    end = html.find(">", begin);
    html.replace(begin, end - begin + 1, "<a>");
  }
}

std::string get_pst(std::string inner)
{
  return "<p class=\"pst\">" + inner + "</p>";
}

void format(std::string& html)
{
  const std::string DES[] = {
    "Description",
    "Input",
    "Output",
    "Sample Input",
    "Sample Output",
    "Hint",
    "Source"
  };
  for (std::string des : DES) {
    std::string pst = get_pst(des);
    std::size_t pos = html.find(pst);
    if (pos == std::string::npos) {
      continue;
    }
    std::string npst = "<h3>" + des + "</h3>";
    html.replace(pos, pst.length(), npst);
  }
  
  std::size_t ptt_begin = html.find("<div class=\"ptt");
  std::size_t ptt_end = html.find("</div>", ptt_begin);
  
  std::size_t title_begin = html.find(">", ptt_begin) + 1;
  std::size_t title_end = html.find("<", title_begin);
  
  std::string title = html.substr(title_begin, title_end - title_begin);
  
  html.replace(ptt_begin, ptt_end - ptt_begin, "<h2 align=\"center\">"
    + title + "</h2>");
}

void raw(int vol, int pro)
{
  static std::string begin_tag("<div class=\"ptt\"");
  static std::string end_tag("</td></tr></table>");
  static std::size_t begin_pos;
  static std::size_t end_pos;
  
  std::string str_vol = int2string(vol);
  std::string str_pro = int2string(pro);
  
  std::string file_path = "pro/" + str_vol + "k/problem?id=" + str_pro;
  std::fstream fin(file_path.c_str(), std::ios::in);
  std::string html;
  
  for (char c; fin.get(c); ) {
    html += c;
  }
  
  begin_pos = html.find(begin_tag);
  end_pos = html.rfind(end_tag) + end_tag.length();
  
  if (begin_pos == std::string::npos || end_pos == std::string::npos) {
    std::cerr << "In pro" << pro << std::endl;
    std::cerr << "    Error: can't fetch content" << std::endl;
    if (begin_pos == std::string::npos) {
      std::cerr << "    Begin can't found" << std::endl;
    }
    if (end_pos == std::string::npos) {
      std::cerr << "    End can't found" << std::endl;
    }
    return;
  }
  
  
  html = html.substr(begin_pos, end_pos - begin_pos);
  remove_link(html);
  format(html);
  
  html = "<meta content=\"text/html; charset=utf-8\">"
    + html;
  
  std::string rfile_path = "pro/r" + str_vol + "k/pro" + str_pro + ".html";
  std::fstream fout(rfile_path.c_str(), std::ios::out);
  
  fout << html << std::endl;
  
  fin.close();
  fout.close();
}

int main()
{
  const int MAX_VOL = 4;
  const int MAX_PRO = 4054;
  const int PP_VOL = 1000;
  
  for (int vi = 1; vi <= MAX_VOL; ++vi) {
    for (int pi = vi * PP_VOL; pi <= MAX_PRO && pi < (vi + 1) * PP_VOL; ++pi) {
      raw(vi, pi);
    }
  }
  
  return 0;
}
