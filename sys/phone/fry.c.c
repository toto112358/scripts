/*
 * config data
 */

#include "sys/param.h"
#include "sys/conf.h"
#include "sys/vtimes.h"
#include "sys/proc.h"
#include "sys/inode.h"
#include "sys/file.h"
#include "sys/text.h"
#include "sys/callout.h"
#include "sys/buf.h"
#include "sys/map.h"
#include "sys/stream.h"
#include "sys/nexus.h"
#include "sys/ubaddr.h"
#include "sys/uba.h"
#include "sys/biaddr.h"
#include "sys/uda.h"
#include "sys/bda.h"
#include "sys/inet/in.h"
#include "sys/inet/ip_var.h"
#include "sys/inet/udp.h"
#include "sys/inet/tcp.h"
#include "sys/inet/tcp_timer.h"
#include "sys/inet/tcp_var.h"
#include "sys/dk.h"
#include "sys/mscp.h"
#include "sys/udaioc.h"
#include "sys/ra.h"
#include "sys/ta.h"
#include "sys/bvp.h"
#include "sys/debna.h"
#include "sys/ttyio.h"
#include "sys/ttyld.h"
#include "sys/bufld.h"
#include "sys/mesg.h"
#include "sys/dkp.h"
#include "sys/mount.h"
extern struct bdevsw cbsbdev;
extern struct bdevsw swbdev;
extern struct bdevsw rabdev;
extern struct bdevsw tabdev;
int nblkdev = 11;
extern struct cdevsw cncdev;
extern struct cdevsw mmcdev;
extern struct cdevsw swcdev;
extern struct cdevsw cbscdev;
extern struct cdevsw bnacdev;
extern struct cdevsw dkcdev;
extern struct cdevsw racdev;
extern struct cdevsw fdcdev;
extern struct cdevsw ipcdev;
extern struct cdevsw tcpcdev;
extern struct cdevsw udpcdev;
extern struct cdevsw tacdev;
int nchrdev = 60;
extern struct fstypsw fsfs;
extern struct fstypsw nafs;
extern struct fstypsw prfs;
extern struct fstypsw msfs;
extern struct fstypsw nbfs;
extern struct fstypsw erfs;
extern struct fstypsw pipfs;
int nfstyp = 7;
extern struct streamtab ttystream;
extern struct streamtab cdkpstream;
extern struct streamtab rdkstream;
extern struct streamtab msgstream;
extern struct streamtab dkpstream;
extern struct streamtab bufldstream;
extern struct streamtab rmsgstream;
extern struct streamtab ipstream;
extern struct streamtab tcpstream;
extern struct streamtab udpstream;
extern struct streamtab connstream;
extern struct streamtab xpstream;
int nstreamtab = 20;

struct bdevsw *bdevsw[] = {
	NULL,
	NULL,
	NULL,
	&cbsbdev,	/* 3 */
	&swbdev,	/* 4 */
	NULL,
	NULL,
	&rabdev,	/* 7 */
	NULL,
	NULL,
	&tabdev,	/* 10 */
};
struct cdevsw *cdevsw[] = {
	&cncdev,	/* 0 */
	NULL,
	NULL,
	&mmcdev,	/* 3 */
	NULL,
	NULL,
	NULL,
	&swcdev,	/* 7 */
	NULL,
	NULL,
	NULL,
	NULL,
	&cbscdev,	/* 12 */
	NULL,
	&bnacdev,	/* 14 */
	NULL,
	NULL,
	&dkcdev,	/* 17 */
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&racdev,	/* 28 */
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&fdcdev,	/* 40 */
	NULL,
	&ipcdev,	/* 42 */
	&tcpcdev,	/* 43 */
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&udpcdev,	/* 50 */
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&tacdev,	/* 59 */
};
struct fstypsw *fstypsw[] = {
	&fsfs,	/* 0 */
	&nafs,	/* 1 */
	&prfs,	/* 2 */
	&msfs,	/* 3 */
	&nbfs,	/* 4 */
	&erfs,	/* 5 */
	&pipfs,	/* 6 */
};
struct streamtab *streamtab[] = {
	&ttystream,	/* 0 */
	&cdkpstream,	/* 1 */
	&rdkstream,	/* 2 */
	NULL,
	&msgstream,	/* 4 */
	&dkpstream,	/* 5 */
	NULL,
	&bufldstream,	/* 7 */
	NULL,
	&rmsgstream,	/* 9 */
	&ipstream,	/* 10 */
	&tcpstream,	/* 11 */
	NULL,
	NULL,
	&udpstream,	/* 14 */
	NULL,
	NULL,
	NULL,
	&connstream,	/* 18 */
	&xpstream,	/* 19 */
};
int proccnt = 600;
struct proc proc[600];
int inodecnt = 1700;
struct inode inode[1700];
int calloutcnt = 50;
struct callout callout[50];
int textcnt = 120;
struct text text[120];
int argcnt = 16;
struct map argmap[16];
int swmapcnt = 600;
struct map swapmap[600];
int kernelcnt = 500;
struct map kernelmap[500];
int swbufcnt = 50;
struct buf swapbuf[50];
struct swapinfo swapinfo[50];
int bufhcnt = 599;
struct bufhd bufhash[599];
int streamcnt = 800;
struct stdata streams[800];
int blkcnt = 1600;
struct block cblock[1600];
int blkbcnt = 20;
struct buf *cblkbuf[20];
int dstflag = 1;
int timezone = 300;
int maxtsize = 12256;

struct nextab nextab[] = {
	0, 0,
	0, 4,
	0, 1,
	0, 3,
	0, 2,
	0, 13,
	-1
};
struct biaddr ubaaddr[] = {
	{0, 0x20, 0x200, 0},
	{1, 0x30, 0x800, 0},
};
int ubacnt = 2;
struct uba uba[2];
struct biaddr bdaddr[] = {
	{2, 0x10, 0x0, 0},
	{3, 0x18, 0x0, 0},
};
int bdcnt = 2;
struct bd bd[2];
struct biaddr biaaddr[] = {
	{4, 0x0, 0x400, 0},
};
int biacnt = 1;
int bianode[1];
struct biaddr bnaaddr[] = {
	{5, 0x40, 0x0, 0},
};
int bnacnt = 1;
struct bnactl bna[1];
struct bnabuf bnabuf[1];
struct ubaddr dkaddr[] = {
	{0767770, 0400, 0},
};
int dkcnt = 256;
struct dk dk[256];
char dkstate[256];
struct ubaddr udaddr[] = {
	{0774500, 0300, 1},
	{0772150, 0260, 0},
	{0760404, 0270, 0},
};
int udcnt = 3;
struct ud ud[3];
extern struct msportsw udport;
extern struct msportsw bdport;
int nmsport = 2;
struct msportsw *msportsw[] = {
	&udport,	/* 0 */
	&bdport,	/* 1 */
};
struct msaddr raaddr[] = {
	{0, 1, 0},
	{1, 1, 1},
	{0, 1, 2},
	{1, 1, 3},
	{0, 1, 4},
	{-1},
	{-1},
	{-1},
	{-1},
	{-1},
	{-1},
	{-1},
	{-1},
	{-1},
	{-1},
	{-1},
	{1, 0, 0},
	{1, 0, 2},
	{1, 0, 4},
};
int racnt = 19;
struct radisk radisk[19];
struct buf rabuf[19];
struct msaddr taaddr[] = {
	{0, 0, 0},
	{2, 0, 0},
	{2, 0, 1},
};
int tacnt = 3;
struct tatape tatape[3];
struct buf tabuf[3];
int cncnt = 0;
int ipcnt = 32;
struct ipif ipif[32];
struct ipif *ipifsort[32];
int udpcnt = 16;
struct udp udpconn[16];
int tcpcnt = 64;
struct tcpcb tcpcb[64];
int arpcnt = 128;
struct ip_arp ip_arps[128];
int ttycnt = 128;
struct ttyld ttyld[128];
int msgcnt = 256;
struct imesg mesg[256];
int rdkcnt = 0;
int xpcnt = 0;
int dkpcnt = 96;
struct dkp dkp[96];
int cdkpcnt = 0;
int bufldcnt = 4;
struct bufld bufld[4];
int fscnt = 24;
struct mount fsmtab[24];
int filecnt = 1536;
struct file file[1536];
int queuecnt = 3072;
struct queue queue[3072];
int maxdsize = 819200;
int maxssize = 819200;
int rootfstyp = 0;
dev_t rootdev = makedev(7, 64);
dev_t swapdev = makedev(4, 0);
struct swdevt swdevt[] = {
	{makedev(7, 4), 249848L},
	{makedev(7, 20), 249848L},
	{makedev(7, 28), 249848L},
};
int nswdevt = 3;
extern int bddump();
int (*dumprout)() = bddump;
int dumpunit = 256;
long dumplow = 530416;
long dumpsize = 249848;
