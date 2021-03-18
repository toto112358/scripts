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
#include "sys/mba.h"
#include "sys/mbaddr.h"
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
#include "sys/subaddr.h"
#include "sys/dz.h"
#include "sys/om.h"
#include "sys/kmc.h"
#include "sys/kdi.h"
#include "sys/mscp.h"
#include "sys/ni1010a.h"
#include "sys/udaioc.h"
#include "sys/ra.h"
#include "sys/tu78.h"
#include "sys/ttyio.h"
#include "sys/ttyld.h"
#include "sys/bufld.h"
#include "sys/mesg.h"
#include "sys/mount.h"
extern struct bdevsw swbdev;
extern struct bdevsw rabdev;
extern struct bdevsw tu78bdev;
int nblkdev = 9;
extern struct cdevsw cncdev;
extern struct cdevsw dzcdev;
extern struct cdevsw mmcdev;
extern struct cdevsw swcdev;
extern struct cdevsw tu78cdev;
extern struct cdevsw kmccdev;
extern struct cdevsw racdev;
extern struct cdevsw kdicdev;
extern struct cdevsw omcdev;
extern struct cdevsw fdcdev;
extern struct cdevsw ipcdev;
extern struct cdevsw tcpcdev;
extern struct cdevsw ilcdev;
extern struct cdevsw udpcdev;
int nchrdev = 51;
extern struct fstypsw fsfs;
extern struct fstypsw nafs;
extern struct fstypsw prfs;
extern struct fstypsw msfs;
extern struct fstypsw nbfs;
extern struct fstypsw erfs;
extern struct fstypsw pipfs;
int nfstyp = 7;
extern struct streamtab ttystream;
extern struct streamtab rdkstream;
extern struct streamtab msgstream;
extern struct streamtab bufldstream;
extern struct streamtab rmsgstream;
extern struct streamtab ipstream;
extern struct streamtab tcpstream;
extern struct streamtab udpstream;
extern struct streamtab connstream;
int nstreamtab = 19;

struct bdevsw *bdevsw[] = {
	NULL,
	NULL,
	NULL,
	NULL,
	&swbdev,	/* 4 */
	NULL,
	NULL,
	&rabdev,	/* 7 */
	&tu78bdev,	/* 8 */
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
	NULL,
	&tu78cdev,	/* 22 */
	NULL,
	NULL,
	NULL,
	&kmccdev,	/* 26 */
	NULL,
	&racdev,	/* 28 */
	NULL,
	NULL,
	&kdicdev,	/* 31 */
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&omcdev,	/* 39 */
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
	&nafs,	/* 1 */
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
	NULL,
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
};

struct nextab nextab[] = {
	0, 0,
	0, 4,
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
int queuecnt = 1024;
struct queue queue[1024];
int streamcnt = 256;
struct stdata streams[256];
int blkcnt = 600;
struct block cblock[600];
int dstflag = 1;
int timezone = 300;
int maxtsize = 12256;
int maxssize = 24544;
struct nxaddr mbaaddr[] = {
	{1, 0, 0x0},
};
int mbacnt = 1;
struct mba mba[1];
extern tm780int();
char mbaid[][8] = {
 0, 01, 02, 03, 04, 05, 06, 07,
};
int mbastray();
int (*mbavec[][8])() = {
 tm780int, mbastray, mbastray, mbastray, mbastray, mbastray, mbastray, mbastray,
};
struct mbaddr tm78addr[] = {
	{0, 0},
};
int tm78cnt = 1;
struct tm78 tm78[1];
struct subaddr tu78addr[] = {
	{0, 0},
};
int tu78cnt = 1;
struct tu78 tu78[1];
struct buf ctu78buf[1];
struct buf rtu78buf[1];
struct nxaddr ubaaddr[] = {
	{2, 0, 0x200},
};
int ubacnt = 1;
struct uba uba[1];
struct ubaddr udaddr[] = {
	{0772150, 0154, 0},
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
struct ubaddr omaddr[] = {
	{0772410, 0124, 0},
	{0772430, 0134, 0},
	{0772450, 0114, 0},
};
int omcnt = 3;
struct om om[3];
struct ubaddr kmcaddr[] = {
	{0760200, 0600, 0},
};
int kmccnt = 1;
struct kmc kmc[1];
struct ubaddr dzaddr[] = {
	{0760100, 0300, 0},
};
int dzcnt = 8;
struct dz dz[8];
struct ubaddr iladdr[] = {
	{0764000, 0340, 0},
};
int ilcnt = 1;
struct il il[1];
int kdicnt = 1;
struct kdikmc kdikmc[1];
struct kmcdk k[1];
int cncnt = 0;
int ttycnt = 32;
struct ttyld ttyld[32];
int msgcnt = 256;
struct imesg mesg[256];
int rdkcnt = 0;
int fscnt = 20;
struct mount fsmtab[20];
int maxdsize = 57280;
int ipcnt = 4;
struct ipif ipif[4];
struct ipif *ipifsort[4];
int udpcnt = 32;
struct udp udpconn[32];
int tcpcnt = 64;
struct tcpcb tcpcb[64];
int arpcnt = 64;
struct ip_arp ip_arps[64];
int bufldcnt = 4;
struct bufld bufld[4];
int blkbcnt = 20;
struct buf *cblkbuf[20];
int rootfstyp = 0;
dev_t rootdev = makedev(7, 64);
dev_t swapdev = makedev(4, 0);
struct swdevt swdevt[] = {
	{makedev(7, 1), 20480L},
	{makedev(7, 9), 20480L},
	{makedev(7, 17), 20480L},
	{makedev(7, 25), 20480L},
};
int nswdevt = 4;
extern int uddump();
int (*dumprout)() = uddump;
int dumpunit = 1;
long dumplow = 10240;
long dumpsize = 20480;
