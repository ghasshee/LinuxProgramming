static char *ename[] = {
    /*      0 */    "",
    /*      1 */    "EPERM", "ENOENT", "ESRCH", "EINTR", "EIO", "ENXIO", "E2BIG",
    /*      8 */    "ENOEXEC", "EBADF", "ECHILD", "EAGAIN/EWOULDBLOCK", "ENOMEM", 
    /*     13 */    "EACCES", "EFALUT", "ENOTBLK", "EBUSY", "EEXIST", "EXDEV",
    /*     19 */    "ENODEV", "ENOTDIR", "ESIDIR", "EINVAL", "ENFILE", "EMFILE", 
    /*     25 */    "ENOTTY", "ETXTBSY", "EFBIG", "ENOSPC", "ESPIPE", "EROFS",
    /*     31 */    "EMLINK", "EPIPE", "EDOM", "ERANGE", "EDEADLK/EDEADLOCK",
    /*     36 */    "ENAMETOOLONG", "ENOLCK", "ENOSYS", "ENOTEMPTY", "ELOOP", "",
    /*     42 */    "ENOMSG", "EIDRM", "ECHRNG", "EL2NSYNC", "EL3HLT", "EL3RST",    
    /*     48 */    "ELNRNG", "EUNATCH", "ENOCSI", "EL2HLT", "EBADE", "EBADR", 
    /*     54 */    "EXFULL", "ENOANO", "EBADRQC", "EBADSLT", "", "EBFONT", "ENOSTR",   
    /*      0 */    "ENODATA", "ETIME", "ENOSR", "ENONET", "ENOPKC", "EREMOTE",
    /*      0 */    "ENOLINK", "EADV", "ESRMNT", "ECOMM", "COMM", "EPROTO", "EMULTIHOP"
    /*      0 */    "EDOTDOT", "EBADMSG", "EOVERFLOW", "ENOTUNIQ", "EBADFD",
    /*      0 */    "EREMECHG", "ELIBACC", "ELIBBAD", "ELIBSCN", "ELIBMAX", 
    /*      0 */    "ELIBEXEC", "EILSEQ", "ERESTART", "ESTRPIPE", "EUSERS",
    /*      0 */    "ENOTSOCK", "EDESTADDRREQ", "EMSGSIZE", "EPROTOTYPE",
    /*      0 */    "ENOPROTOOPT", "EPROTONOSUPPORT", "ESOCKTNOSUPPORT",
    /*      0 */    "EOPNOTSUPP/ENOTSUP", "EPFNOSUPPORT", "EAFNOSUPPORT",
    /*      0 */    "EADDRINUSE", "EADDRNOTAVAIL", "ENETDOWN", "ENETUNREACH",
    /*      0 */    "ENETRESET", "ECONNABORTED", "ECONNRESET", "ENOBUFS", "EISCONN",
    /*      0 */    "ENOTCONN", "ESHUTDOWN", "ETOOMANYREFS", "ETIMEDOUT",
    /*      0 */    "ECONNREFUSED", "EHOSTDOWN", "EHOSTUNREACH", "EALREADY",
    /*      0 */    "EINPROGRESS", "ESTALE", "EUCLEAN", "ENOTNAM", "ENAVAIL",
    /*      0 */    "EISNAM", "EREMOTEIO", "EDQUOT", "ENDMEDIUM", "EMEDIUMTYPE",
    /*      0 */    "ECANCELED", "ENOKEY", "EKEYEXPIRED", "EKEYREVOKED",
    /*      0 */    "EKEYREJECTED", "EOWNERDEAD", "ENOTRECOVERABLE", "ERFKILL"
};

#define MAX_ENAME 132
