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
#include "sys/nxaddr.h"
#include "sys/nexus.h"
#include "sys/ubaddr.h"
#include "sys/uba.h"
#include "sys/uda.h"
#include "sys/inet/in.h"
#include "sys/inet/ip_var.h"
#include "sys/inet/udp.h"
#include "sys/inet/tcp.h"
#include "sys/inet/tcp_timer.h"
#include "sys/inet/tcp_var.h"
#include "sys/dz.h"
#include "sys/mg.h"
#include "sys/kmc.h"
#include "sys/kdi.h"
#include "sys/kb.h"
#include "sys/mscp.h"
#include "sys/ni1010a.h"
#include "sys/udaioc.h"
#include "sys/ra.h"
#include "sys/ttyio.h"
#include "sys/ttyld.h"
#include "sys/bufld.h"
#include "sys/mesg.h"
#include "sys/dkp.h"
#include "sys/mount.h"
extern struct bdevsw swbdev;
extern struct bdevsw rabdev;
int nblkdev = 8;
extern struct cdevsw cncdev;
extern struct cdevsw dzcdev;
extern struct cdevsw mmcdev;
extern struct cdevsw swcdev;
extern struct cdevsw kbcdev;
extern struct cdevsw dncdev;
extern struct cdevsw kmccdev;
extern struct cdevsw racdev;
extern struct cdevsw kdicdev;
extern struct cdevsw mgcdev;
extern struct cdevsw fdcdev;
extern struct cdevsw ipcdev;
extern struct cdevsw tcpcdev;
extern struct cdevsw ilcdev;
extern struct cdevsw udpcdev;
int nchrdev = 51;
extern struct fstypsw fsfs;
extern struct fstypsw prfs;
extern struct fstypsw msfs;
extern struct fstypsw nbfs;
extern struct fstypsw erfs;
extern struct fstypsw pipfs;
int nfstyp = 7;
extern struct streamtab ttystream;
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
	NULL,
	&swbdev,	/* 4 */
	NULL,
	NULL,
	&rabdev,	/* 7 */
};
struct cdevsw *cdevsw[] = {
	&cncdev,	/* 0 */
	&dzcdev,	/* 1 */
	NULL,
	&mmcdev,	/* 3 */
	NULL,
	NULL,
	NULL,
	&swcdev,	/* 7 */
	NULL,
	NULL,
	&kbcdev,	/* 10 */
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&dncdev,	/* 19 */
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&kmccdev,	/* 26 */
	NULL,
	&racdev,	/* 28 */
	NULL,
	NULL,
	&kdicdev,	/* 31 */
	&mgcdev,	/* 32 */
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
	&ilcdev,	/* 44 */
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&udpcdev,	/* 50 */
};
struct fstypsw *fstypsw[] = {
	&fsfs,	/* 0 */
	NULL,
	&prfs,	/* 2 */
	&msfs,	/* 3 */
	&nbfs,	/* 4 */
	&erfs,	/* 5 */
	&pipfs,	/* 6 */
};
struct streamtab *streamtab[] = {
	&ttystream,	/* 0 */
	NULL,
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

struct nextab nextab[] = {
	0, 0,
	0, 8,
	-1
};
struct nxaddr mcraddr[] = {
	{0, 0, 0x0},
};
int mcrcnt = 1;
caddr_t mcrregs[1];
time_t mcrtime[1];
int proccnt = 300;
struct proc proc[300];
int filecnt = 500;
struct file file[500];
int inodecnt = 700;
struct inode inode[700];
int calloutcnt = 50;
struct callout callout[50];
int textcnt = 60;
struct text text[60];
int argcnt = 16;
struct map argmap[16];
int swmapcnt = 200;
struct map swapmap[200];
int kernelcnt = 100;
struct map kernelmap[100];
int swbufcnt = 50;
struct buf swapbuf[50];
struct swapinfo swapinfo[50];
int bufhcnt = 63;
struct bufhd bufhash[63];
int dstflag = 1;
int timezone = 300;
int maxtsize = 12256;
struct nxaddr ubaaddr[] = {
	{1, 0, 0x200},
};
int ubacnt = 1;
struct uba uba[1];
struct ubaddr udaddr[] = {
	{0772150, 0254, 0},
};
int udcnt = 1;
struct ud ud[1];
extern struct msportsw udport;
int nmsport = 1;
struct msportsw *msportsw[] = {
	&udport,	/* 0 */
};
struct msaddr raaddr[] = {
	{0, 0, 0},
	{0, 0, 1},
	{0, 0, 2},
	{0, 0, 3},
};
int racnt = 4;
struct radisk radisk[4];
struct buf rabuf[4];
struct ubaddr dzaddr[] = {
	{0760100, 0300, 0},
	{0760110, 0310, 0},
};
int dzcnt = 16;
struct dz dz[16];
struct ubaddr dnaddr[] = {
	{0775200, 0430, 0},
};
int dncnt = 1;
caddr_t dnreg[1];
struct ubaddr mgaddr[] = {
	{0767720, 0360, 0},
};
int mgcnt = 1;
struct mg mg[1];
struct ubaddr draddr[] = {
	{0767570, 00, 0},
};
int drcnt = 1;
caddr_t drreg[1];
struct ubaddr iladdr[] = {
	{0764000, 0340, 0},
	{0765000, 0350, 0},
};
int ilcnt = 2;
struct il il[2];
struct ubaddr kmcaddr[] = {
	{0760200, 0600, 0},
};
int kmccnt = 1;
struct kmc kmc[1];
int kdicnt = 1;
struct kdikmc kdikmc[1];
struct kmcdk k[1];
int kbcnt = 256;
struct kb kb[256];
char kbstate[256];
int cncnt = 0;
int ttycnt = 32;
struct ttyld ttyld[32];
int msgcnt = 64;
struct imesg mesg[64];
int rdkcnt = 0;
int dkpcnt = 256;
struct dkp dkp[256];
int xpcnt = 0;
int bufldcnt = 32;
struct bufld bufld[32];
int fscnt = 10;
struct mount fsmtab[10];
int ipcnt = 32;
struct ipif ipif[32];
struct ipif *ipifsort[32];
int udpcnt = 32;
struct udp udpconn[32];
int tcpcnt = 64;
struct tcpcb tcpcb[64];
int arpcnt = 128;
struct ip_arp ip_arps[128];
int blkcnt = 700;
struct block cblock[700];
int blkbcnt = 40;
struct buf *cblkbuf[40];
int streamcnt = 512;
struct stdata streams[512];
int queuecnt = 2048;
struct queue queue[2048];
int maxdsize = 32000;
int maxssize = 32000;
int rootfstyp = 0;
dev_t rootdev = makedev(7, 64);
dev_t swapdev = makedev(4, 0);
struct swdevt swdevt[] = {
	{makedev(7, 1), 20480L},
	{makedev(7, 9), 20480L},
};
int nswdevt = 2;
extern int uddump();
int (*dumprout)() = uddump;
int dumpunit = 1;
long dumplow = 10240;
long dumpsize = 20480;
