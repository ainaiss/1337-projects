#include "response_generator.hpp"

const webserv::http_map webserv::http_mapper;

webserv::http_map::http_map() {
    status_code[100] = "100 Continue";
    status_code[101] = "101 Switching Protocols";
    status_code[200] = "200 OK";
    status_code[201] = "201 Created";
    status_code[202] = "202 Accepted";
    status_code[203] = "203 Non-Authoritative Information";
    status_code[204] = "204 No Content";
    status_code[205] = "205 Reset Content";
    status_code[206] = "206 Partial Content";
    status_code[300] = "300 Multiple Choices";
    status_code[301] = "301 Moved Permanently";
    status_code[302] = "302 Found";
    status_code[303] = "303 See Other";
    status_code[304] = "304 Not Modified";
    status_code[305] = "305 Use Proxy";
    status_code[307] = "307 Temporary Redirect";
    status_code[400] = "400 Bad Request";
    status_code[401] = "401 Unauthorized";
    status_code[402] = "402 Payment Required";
    status_code[403] = "403 Forbidden";
    status_code[404] = "404 Not Found";
    status_code[405] = "405 Method Not Allowed";
    status_code[406] = "406 Not Acceptable";
    status_code[407] = "407 Proxy Authentication Required";
    status_code[408] = "408 Request Timeout";
    status_code[409] = "409 Conflict";
    status_code[410] = "410 Gone";
    status_code[411] = "411 Length Required";
    status_code[412] = "412 Precondition Failed";
    status_code[413] = "413 Request Entity Too Large";
    status_code[414] = "414 Request-URI Too Long";
    status_code[415] = "415 Unsupported Media Type";
    status_code[416] = "416 Requested Range Not Satisfiable";
    status_code[417] = "417 Expectation Failed";
    status_code[500] = "500 Internal Server Error";
    status_code[501] = "501 Not Implemented";
    status_code[502] = "502 Bad Gateway";
    status_code[503] = "503 Service Unavailable";
    status_code[504] = "504 Gateway Timeout";
    status_code[505] = "505 HTTP Version Not Supported";

    content_type["aac"] = "audio/aac";
    content_type["abw"] = "application/x-abiword";
    content_type["arc"] = "application/x-freearc";
    content_type["avi"] = "video/x-msvideo";
    content_type["azw"] = "application/vnd.amazon.ebook";
    content_type["bin"] = "application/octet-stream";
    content_type["bmp"] = "image/bmp";
    content_type["bz"] = "application/x-bzip";
    content_type["bz2"] = "application/x-bzip2";
    content_type["csh"] = "application/x-csh";
    content_type["css"] = "text/css";
    content_type["csv"] = "text/csv";
    content_type["doc"] = "application/msword";
    content_type["docx"] =
        "application/"
        "vnd.openxmlformats-officedocument.wordprocessingml.document";
    content_type["eot"] = "application/vnd.ms-fontobject";
    content_type["epub"] = "application/epub+zip";
    content_type["gz"] = "application/gzip";
    content_type["gif"] = "image/gif";
    content_type["htm"] = "text/html";
    content_type["html"] = "text/html";
    content_type["ico"] = "image/vnd.microsoft.icon";
    content_type["ics"] = "text/calendar";
    content_type["jar"] = "application/java-archive";
    content_type["jpeg"] = "image/jpeg";
    content_type["jpg"] = "image/jpeg";
    content_type["js"] = "text/javascript";
    content_type["json"] = "application/json";
    content_type["jsonld"] = "application/ld+json";
    content_type["mid"] = "audio/midi";
    content_type["midi"] = "audio/midi";
    content_type["mjs"] = "text/javascript";
    content_type["mp3"] = "audio/mpeg";
    content_type["mpeg"] = "video/mpeg";
    content_type["mpkg"] = "application/vnd.apple.installer+xml";
    content_type["odp"] = "application/vnd.oasis.opendocument.presentation";
    content_type["ods"] = "application/vnd.oasis.opendocument.spparsesheet";
    content_type["odt"] = "application/vnd.oasis.opendocument.text";
    content_type["oga"] = "audio/ogg";
    content_type["ogv"] = "video/ogg";
    content_type["ogx"] = "application/ogg";
    content_type["opus"] = "audio/opus";
    content_type["otf"] = "font/otf";
    content_type["png"] = "image/png";
    content_type["pdf"] = "application/pdf";
    content_type["php"] = "application/x-httpd-php";
    content_type["ppt"] = "application/vnd.ms-powerpoint";
    content_type["pptx"] =
        "application/"
        "vnd.openxmlformats-officedocument.presentationml.presentation";
    content_type["rar"] = "application/vnd.rar";
    content_type["rtf"] = "application/rtf";
    content_type["sh"] = "application/x-sh";
    content_type["svg"] = "image/svg+xml";
    content_type["swf"] = "application/x-shockwave-flash";
    content_type["tar"] = "application/x-tar";
    content_type["tif"] = "image/tiff";
    content_type["tiff"] = "image/tiff";
    content_type["ts"] = "video/mp2t";
    content_type["ttf"] = "font/ttf";
    content_type["txt"] = "text/plain";
    content_type["vsd"] = "application/vnd.visio";
    content_type["wav"] = "audio/wav";
    content_type["weba"] = "audio/webm";
    content_type["webm"] = "video/webm";
    content_type["webp"] = "image/webp";
    content_type["woff"] = "font/woff";
    content_type["woff2"] = "font/woff2";
    content_type["xhtml"] = "application/xhtml+xml";
    content_type["xls"] = "application/vnd.ms-excel";
    content_type["xlsx"] = "application/vnd.openxmlformats-officedocument.spparsesheetml.sheet";
    content_type["xml"] = "application/xml";
    content_type["xul"] = "application/vnd.mozilla.xul+xml";
    content_type["zip"] = "application/zip";
    content_type["3gp"] = "video/3gpp";
    content_type["3g2"] = "video/3gpp2";
    content_type["7z"] = "application/x-7z-compressed";
}

webserv::http_map::~http_map() {}

bool webserv::http_map::contains_status_code(std::size_t code) const {
    return status_code.find(code) != status_code.end();
}

bool webserv::http_map::contains_content_type(const std::string &type) const {
    return content_type.find(type) != content_type.end();
}
